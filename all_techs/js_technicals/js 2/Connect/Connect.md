# Connect

Implement a variant of Connect 4, where:
- Instead of Connect 4, it's actually Connect K (where K is input to the class)
- The board is infinitely wide
- Tokens are inserted at the bottom of columns, shifting all existing tokens up (instead of being placed on top)

The class to implement is:
```
class Connect {
    Connect(int k) {
    
    }
    
    // Returns whether someone has wone the game after this move
    boolean play(Token token, int column) {
    
    }

}
```

## Parts
- **Part 1:** Implement `play` where the game is only won if you have k-in-a-row vertically
- **Part 2:** Now support `k-in-a-row` horizontally
- **Part 3:** Now support `k-in-a-row` diagonally
