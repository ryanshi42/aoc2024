# Stack Machine
memory: stack 
data: string|int 
program: list of instructions

instructions:
- Push [string|int]: push value onto the stack
- Pop: remove the value on the top of the stack
- Print: print the top of the stack (do not pop)
- Add: remove top 2 elements of the stack, push their `sum`
  - both int -> integer addition
  - otherwise string concat
- Jump [idx]: unconditional jump to instruction
- Jnz [idx]: jump to instruction if top of the stack is not the number 0

## Part 1
Write a function `run(program: list[Instruction])` to execute a program.

## Part 2
Write a function `debug(program: list[Instruction])` that returns a new program, which is the original program but with debugging prints added to all jump instructions (`Jump` and `Jnz`).

i.e. immediately before `Jump x` is executed the program should print `"Jump x"`
