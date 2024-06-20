# Position Manager
## Part 1 - Simple Position Manager
Create a position manager class, it has two methods:
```java
void handleTrade(Trade trade);
int getPosition(String symbol);
```
where `Trade` has `symbol`, `side` (BUY or SELL) and `volume` (positive integer).

## Part 2 - Subscriptions
Support subscribing to updates in the position of a symbol, the API is:
```java
void handleSubscription(int clientId, String symbol);
void handleDisconnect(int clientId);
```
Send updates to clients:
- when they first subscribe
- whenever the volume of the subscribed symbol changes

You're given a magic JS black box function to send the update:
```java
void sendUpdateToClient(int clientId, String symbol, int position);
```

## Part 3 - Rate Limiting
Now you want to avoid spamming clients with updates faster than they can handle them. The rules for the rate limiting are:
1. Only one packet in flight for each client
2. Always send up-to-date positions
3. Send updates for symbol with earliest changed position first

The manager gets a new method to support this:
```java
// Called to signal client has handled its most recent msg
// i.e. no longer in flight
void handleClientAck(int clientId);
```

## Part 4 - Advanced Rate Limiting
The rules of rate limiting have changed, now:
1. At most 5 packets can be in-flight for each client
2. We can only have one update for a given symbol in flight to a client
Rules 2 and 3 from above still apply, however if the earliest changed symbol(s) currently have a message in flight then you need to send the first one that does not.

No changes to the API.

Also you can assume that packets are ACK'd in the order they were sent (TCP 🤩).
