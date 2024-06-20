# Spreadsheet
Implement a spreadsheet class with the following methods:
```java
// Evaluate a cell. Raise error if:
// - This cell or one of it's dependencies is empty
// - This cell has a circular dependency
int evaluate(int position);

// Set cell to a constant value
void setConst(int position, int value);

// Set cell to be the sum of two other cells
void setSum(int position, int src1, int src2);
```
Cell references are just integer positions - don't need to worry about 2D or shit like A13.

- **Part 1:** Implement `evaluate` - don't worry about circular dependencies for now
- **Part 2:** Do caching of evaluates (nothing fancy)
- **Part 3:** Worry about circular dependencies now
- **Part 4:** Implement the `set` methods - this should do some cache invalidation
