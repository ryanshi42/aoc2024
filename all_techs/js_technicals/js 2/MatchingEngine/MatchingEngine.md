# MatchingEngine

Write a trading matching engine, which matches orders:
```
Order:
  symbol:   string # e.g "IBM"
  price:    float  # $100
  quantity: int    # 100 shares
  side:     "buy" or "sell"
```

Orders are matched on price-time priority, which means when an order comes in:
- It trades with the order in the book with the best price
  - Note that: buys trade with the lowest sell, sells trade with the highest buy
- If there are multiple orders with the same price, trade with the one that was submitted earliest
- If there are no orders that it's possible to trade with in the book, add the order to the book
  - Note that: a buy order will not trade with a sell order with a greater price, and vice versa

Examples:
```
Jack BUY 100 IBM at $100
Keloysius SELL 100 IBM at $100
Trade -> 100 IBM -> $100

Jack BUY 100 IBM at $100
Keloysius SELL 100 IBM at $200
No trade

Jack BUY 100 IBM at $100
Keloysius SELL 100 IBM at $90
Trade -> 100 IBM -> $100

Keloysius SELL 100 IBM at $90
Jack BUY 100 IBM at $100
Trade -> 100 IBM -> $90

# Price Priority
Jack BUY 100 IBM at $90
Keloysius BUY 100 IBM at $100
Ting Hao SELL 100 IBM at $90
Trade -> 100 IBM -> $100 (KELOYSIUS / TING HAO)

Jack SELL 100 IBM at $100
Keloysius SELL 100 IBM at $110
Ting Hao BUY 100 IBM at $200
Trade -> 100 IBM -> $100 (TING HAO / JACK)

# Time Priority
Jack BUY 100 IBM at $90
Keloysius BUY 100 IBM at $90
Ting Hao SELL 100 IBM at $90
Trade -> 100 IBM -> $90 (JACK / TING HAO)
```

The class methods you need to implement are:
```
void send_order(client_name:string, client_order_id: int, symbol:string, price:float, quantity:int, side:("buy" or "sell"))
void cancel_order(client_name:string, client_order_id:int)
```
And you are given the following function to report when orders are traded:
```
notify_order_traded(client_name:string, client_order_id:int, price:float)
```

Notes:
- `client_order_id` is only unique per client (i.e. Jack and Keloysius may both have orders with id 0)

## Parts
For Part 1 assume that all orders have equal quantity (say 100), such that all orders either trade completely with a single order, or trade with nothing and enter the book.

For Part 2, orders can have different quantities. This means an incoming order may trade with multiple other resting orders in the book before either being filled, or left in the book because there are no more orders it can trade against.