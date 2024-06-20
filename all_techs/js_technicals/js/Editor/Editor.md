# Editor

Given a list of lines of code, we want to format it so that:
- It is correctly indented
- There are toggle buttons to collapse code blocks (start as `-`, and become `+` when toggled)
You can assume that the opening `{` of each code block is at the end of a line, and the closing `}` is on it's own line.

Example input (the numbers and line down the left are not part of the problem, dw about them):
```
// 00. | set hello "world"
// 01. | proc Factorial (x) {
// 02. | set accumulator 1
// 03. | set i x
// 04. | if ($i == 1) {
// 05. | return 1
// 06. | }
// 07. | while ($i >= 2) {
// 08. | set accumulator [ expr $i * $accumulator ]
// 09. | set i [ expr $i - 1 ]
// 10. | }
// 11. | }
```
Formatted output:
```
// 00. |   set hello "world"
// 01. | - proc Factorial (x) {
// 02. |     set accumulator 1
// 03. |     set i x
// 04. | -   if ($i == 1) {
// 05. |       return 1
// 06. |     }
// 07. | -   while ($i >= 2) {
// 08. |       set accumulator [ expr $i * $accumulator ]
// 09. |       set i [ expr $i - 1 ]
// 10. |     }
// 11. |   }
```
Toggle code block at line 4:
```
// 00. |   set hello "world"
// 01. | - proc Factorial (x) {
// 02. |     set accumulator 1
// 03. |     set i x
// 04. | +   if ($i == 1) { ... }
// 05. | -   while ($i >= 2) {
// 06. |       set accumulator [ expr $i * $accumulator ]
// 07. |       set i [ expr $i - 1 ]
// 08. |     }
// 09. |   }
```
Note that the line numbers change, so toggling a block at line 5 should now work. Also, note that if the enclosing block of a collapsed block is collapsed, it should still be collapsed when the enclosing block is expanded again.

## Part 1
Part 1 is to implement a function `Map<Int,Int> findCodeBlocks(List<String> lines)` that returns a map, where each key is the line number of the start of a block, and the value is the line number of the end of the block.

## Part 2
Implement the editor class, the interface is:
```
class Editor {
    Editor(List<String> sourceCode) {
    
    }
    
    void toggleBlock(int lineNumber) {
    
    }
}
```
You get given a function `display(List<String> lines)` to print out the formatted lines (which generates the line numbers for you).