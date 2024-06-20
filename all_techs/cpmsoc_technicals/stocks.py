n, S, r = map(int, input().split())
price = []
quantity = []
for i in range(n):
    p, q = map(int, input().split())
    price.append(p)
    quantity.append(q)

stocks = list(zip(price, quantity))
# print(stocks)
stocks.sort()
profit = 0
for stock in stocks:
    if stock[0] < S:
        amt_bought = min(r // stock[0], stock[1])
        r -= stock[0] * amt_bought
        profit += amt_bought * S

# print(profit, r)
print(profit + r)
