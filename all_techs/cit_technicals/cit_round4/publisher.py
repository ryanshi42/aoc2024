
import time

class Publisher:
    
    def __init__(self):
        self.stocks = {}
        self.chunk_counter = 0

    def publish(self, time, key, price):
        print(f'PUBLISH    time={time} key={key} price={price}')

    def on_price(self, time, key, price):
        self.stocks[key] = price
        self.publish(time, key, price)

    def on_poll_time(self, poll_time):
        print(f'POLL_START time={poll_time}')

        # temp_stocks = self.stocks.items()

        num_stocks = len(self.stocks)
        num_divisor = 3
        stocks_in_chunk = max(num_stocks // num_divisor, 1)
        
        for (stock_name, price) in list(self.stocks.items())[stocks_in_chunk * self.chunk_counter:stocks_in_chunk * (self.chunk_counter + 1)]:
            # time.sleep(2)
            self.publish(poll_time, stock_name, price)

        self.chunk_counter = (self.chunk_counter + 1) % (min(num_stocks, num_divisor))
        print(f'POLL_END   time={poll_time}')


# price for a stock
# publishing on multicast
# apps are listening for the multicast msgs
# listens to 1000s of ASX
# exceeeds send buffer, NIC, rcv buffer, or client buffer
# 

# def init():

pub = Publisher()
# timer.register_timer(5000ms, 
# timer.register_timer(10ms, 

# client1 joins here
pub.on_price(0, "A", 1.0)
pub.on_price(0, "B", 2.0)
pub.on_poll_time(0)
pub.on_poll_time(1)
pub.on_poll_time(2)

pub.on_price(3, "C", 3.0)
pub.on_poll_time(3)
pub.on_poll_time(4)
pub.on_poll_time(5)
pub.on_poll_time(6)
# client2 joins here
pub.on_price(7, "A", 1.1)
pub.on_poll_time(7)
pub.on_price(8, "B", 2.1)
pub.on_poll_time(8)
pub.on_poll_time(9)
pub.on_poll_time(10)
pub.on_poll_time(11)
pub.on_poll_time(12)
pub.on_price(12, "A", 1.2)
pub.on_poll_time(13)
pub.on_price(13, "B", 2.2)
pub.on_poll_time(14)

# print(hash("bob"))
# print(hash(-2))
# print(hash(2))