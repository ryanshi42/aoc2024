# Make 24

The game Make 24 is: given 4 integers, can you rearrange and combine them using +, -, *, / and bracketing to make 24.

## Part 1
Implement an equation evaluator, takes in a string like
```
(3 - 1) * 4 + 5
```
You're given a magic helper function that returns the index of the "outermost" operator, which in this case is the `+`
between 4 and 5. The outermost operator in `(3 - 1) * 4` is the `*`.

## Part 2
Given a list of 4 integers, find and print an equation that combines them to make 24.