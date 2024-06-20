# import requests
# import mysql.connector
# import pandas as pd

from bisect import bisect_left, insort
from collections import defaultdict
import Reader

class Order:
    """A helper Order class that would be a struct in other languages"""
    def __init__(self, order_id : int, side : str, volume : int, price : int):
        self.order_id = order_id
        self.side = side
        self.volume = volume
        self.price = price

class PriceLevel:
    """Helper class for the price level."""
    def __init__(self, price: int, volume: int):
        self.price = price
        self.total_volume = volume

    def get_price(self):
        return self.price

    def get_total_volume(self):
        return self.total_volume

    def add_to_total_volume(self, new_volume: int):
        self.total_volume += new_volume
    
    def get_repr(self):
        return (self.price, self.total_volume)


def get_best_from_side(order_book, side):
    """Formats the best buys and sells nicely for output."""
    order_book_side = order_book[side]
    return order_book_side[:2]

def main():
    reader = Reader()
    
    order_book = defaultdict(lambda : None)
    id_to_order = defaultdict(lambda : None)
    
    while reader.read("market_data.pcap"):
        print(reader.msg) # print out current message
        symbol_order_book = None
        
        # Magic function
        header, order = parse_order(reader.msg)

        if header.msg_type == "A":
            insert_order(order_book, id_to_order, header.seq_num, order.order_id, order.side, order.volume, order.price)
        elif header.msg_type == "M":
            modify_order(order_book, id_to_order, header.seq_num, order.order_id, order.volume)
        elif header.msg_type == "T":
            trade_order(order_book, id_to_order, header.seq_num, order.order_id, counterparty_order_id, order.side, order.volume, order.price)
        elif header.msg_type == "D":
            delete_order(order_book, id_to_order, header.seq_num, order.order_id)
        else:
            print("Unknown message type, skipping!")
        # (msg is a Message object with attributes listed in the specs above)
    return 0

if __name__ == "__main__":
    main()

def remove_price_level(order_book, price_levels, side, price):
    """
        Removes a price level from the OrderBook. 
        This is an O(n) operation for the above reasons, we have used bisect_left simply to illustrate this could be faster with a hypothetical RB tree.
    """
    order_book_side = order_book.get_order_book_by_side(side)
    price_levels.pop(price)
    if side == "buy":
        order_book_side.pop(bisect_left(order_book_side, -price, key=lambda x: -x.get_price()))
    else:
        order_book_side.pop(bisect_left(order_book_side, price, key=lambda x: x.get_price())) 



def insert_order(order_book : dict, id_to_order : dict, order_id : int, side : str, volume : int, price : int):
    """
        Inserts an order into the order book.
        Deals with error cases and also the two cases where a) the price level exists or b) the price level doesn't exist.
    """

    # we don't check for prices being negative as per the spec it could be the case
    if volume <= 0:
        print("Invalid volume provided")
        return

    # create a new order
    id_to_order[(order_id, side)] = Order(order_id, side, volume, price)

    # memoization: if the price already exists, no need to search for it
    # we only generate the string if we need to as well
    # we also cache the price levels in a dictionary
    # print("INSERT", order_id, order_book, side, price, volume)
    price_levels = order_book.get_price_levels_by_side(side)
    if price in price_levels:
        price_levels[price].add_to_total_volume(volume)
        return 

    best_orders = order_book.get_order_book_by_side(side)
    new_plevel = PriceLevel(price, volume)

    # Buy should be sorted highest bid first
    # In theory this is an O(log n) insert but because you have to shift all array elements up one from the position of insert
    # the insertion is really dominated by an O(n) here
    if side == "buy":
        insort(best_orders, new_plevel, key=lambda x: -x.get_price())
    else:
        insort(best_orders, new_plevel, key=lambda x: x.get_price()) 

    # notice that this insert works even if the list is empty
    price_levels[price] = new_plevel
    return



# There is a bit of code repetition in how these are handled, but I personally believe the functions are sufficiently different to not need to use a helper function
def trade_order(order_book : dict, id_to_order : dict, order_id : int, side : str, volume : int):
    """
        Executes a traded order.
    """
    if (order_id, side) not in id_to_order:
        print("Invalid order ID provided!")
        return

    if volume <= 0:
        print("Invalid volume provided!")
        return

    price_levels = order_book.get_price_levels_by_side(side)
    order_info = id_to_order[(order_id, side)]
    if order_info.price not in price_levels:
        print("Invalid price provided!")
        return
    
    # print("TRADE", order_id, order_book, side, order_info.price, order_info.volume)

    # Get current order info and remove it if there is no volume on it left
    remaining_volume = order_info.volume - volume

    if remaining_volume == 0:
        id_to_order.pop((order_id, side))
    order_info.volume = remaining_volume

    # the price level must be already existing for this to work
    price_levels[order_info.price].add_to_total_volume(-volume)
    if price_levels[order_info.price].get_total_volume() == 0:
        remove_price_level(order_book, price_levels, side, order_info.price)
    return



def modify_order(order_book : dict, id_to_order : dict, order_id : int, side : str, volume : int, new_price : int):
    """
        Uses the insert function to insert orders as well as update the existing order
    """
    if (order_id, side) not in id_to_order:
        print("Invalid order ID provided!")
        return

    if volume <= 0:
        print("Invalid volume provided!")
        return

    price_levels = order_book.get_price_levels_by_side(side)
    order_info = id_to_order[(order_id, side)]
    if order_info.price not in price_levels:
        print("Invalid price provided!")
        return

    # print("UPDATE", order_id, order_book, side, order_info.price, order_info.volume, new_price, volume)
    # the price level must be already existing for this to work
    # If price level is the same, we can return early
    price_levels[order_info.price].add_to_total_volume(volume - order_info.volume)
    order_info.volume = volume

    if price_levels[order_info.price].get_total_volume() == 0:
        remove_price_level(order_book, price_levels, side, order_info.price)
        
    return



# There is a bit of code repetition in how these are handled, but I personally believe the functions are sufficiently different to not need to use a helper function
def delete_order(order_book : dict, id_to_order : dict, order_id : int, side : str):
    """
        Checks if an order is valid and deletes it
    """
    if (order_id, side) not in id_to_order:
        print("Invalid order ID provided!")
        return

    price_levels = order_book.get_price_levels_by_side(side)
    order_info = id_to_order[(order_id, side)]
    if order_info.price not in price_levels:
        print("Invalid price provided!")
        return

    price_levels[order_info.price].add_to_total_volume(-order_info.volume)
    # print("DELETE", order_id, order_book, side, order_info.price, order_info.volume)
    if price_levels[order_info.price].get_total_volume() == 0:
        remove_price_level(order_book, price_levels, side, order_info.price)

    id_to_order.pop((order_id, side))
    return