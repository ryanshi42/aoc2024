# Order:
#   symbol:   string # e.g "IBM"
#   price:    float  # $100
#   quantity: int    # 100 shares
#   side:     "buy" or "sell"

# 1 buy 100 IBM @ $100
# 2 buy 100 IBM @ $101
# 3 sell 100 IBM @ $99

# to implement
# Exchange:
#   # we're going to assume quantity=100 for all orders
#   void send_order(client_name:string, client_order_id: int, symbol:string, price:float, quantity:int, side:("buy" or "sell"))
#   
#   void cancel_order(client_name:string, client_order_id:int)
# 
# # provided
# notify_order_added(client_name:string, client_order_id:int)
# notify_order_canceled(client_name:string, client_order_id:int)
# notify_order_filled(client_name:string, client_order_id:int, price:float)

class Order:
    def __init__(self, client_name:string, client_order_id: int, symbol:string, price:float, quantity:int, side:("buy" or "sell")):
        self.client_name = client_name
        pass

from collections import deque, defaultdict
# from bisect import bisect_left

class Exchange:
    def __init(self):
        # insert : [Node(price:100), Node(price:200)]
            # trade : 
        # cancel : 

        self.symbols = defaultdict(lambda : {"buys": deque([]), "sells": deque([])})
        self.client_orders = defaultdict(lambda : None)

        pass

    def check_cross(self, resting_order, new_order):
        if new_order.get_side() == "buy":
            return resting_order.get_price() <= new_order.get_price()
        if new_order.get_side() == "sell":
            return resting_order.get_price() >= new_order.get_price()
    

    def send_order(client_name:string, client_order_id: int, symbol:string, price:float, quantity:int, side:("buy" or "sell")):
        new_order = Order(client_name:string, client_order_id: int, symbol:string, price:float, quantity:int, side:("buy" or "sell"))
        # check if cross
        opposite = "buy" if side == "sell" else "sell"
        # for value in self.symbols[opposite].reversed():
        has_crossed = False
        if self.symbols[opposite]:
            top_level_order = self.symbols[opposite][-1]
            top_level_price = top_level_order.get_price()
            if self.check_cross(top_level_order, new_order):
                notify_order_filled(client_name:string, client_order_id:int, top_level_price:float)
                notify_order_filled(top_level_order.get_client_name(), top_level_order.get_client_order_id(), top_level_price)
                
                self.symbols[opposite].pop()
                self.client_orders.remove((top_level_order.get_client_name(), top_level_order.client_order_id()))
                has_crossed = True

        if not has_crossed:
            for idx, value in enumerate(self.symbols[side]):
                if side == "buy" and value < price:
                    self.symbols[side].insert(idx)
                if side == "sell" and value > price:
                    self.symbols[side].insert(idx)
            self.client_orders[(client_name, client_order_id)] = new_order
            notify_order_added(client_name:string, client_order_id:int)
        

    def cancel_order(self, client_name:string, client_order_id:int):
        if (client_name, client_order_id) not in self.client_orders:
            raise Error()
        # otherwise can assume that it is valid
        order_to_delete = self.client_orders[(client_name, client_order_id)]
        order_symbol = order_to_delete.get_symbol()
        order_side = order_to_delete.get_side()

        # O(n) operation
        self.symbols[order_symbol][order_side].remove(order_to_delete)
        self.client_orders.remove((client_name, client_order_id))

        notify_order_canceled(client_name:string, client_order_id:int)
