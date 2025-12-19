*This project has been created as part of the 42 curriculum by onoras*

# push_swap

**push_swap** is a program that sorts a stack of integers using the minimum number of operations.  
It outputs a sequence of instructions to sort the stack in ascending order, such as `sa`, `pb`, `ra`, etc.  
The goal of the project is to implement an efficient sorting algorithm using a limited set of stack operations.

## Description

The project involves sorting a stack with only two stacks allowed (`a` and `b`) and a set of operations:  
- Swap: `sa`, `sb`, `ss`  
- Push: `pa`, `pb`  
- Rotate: `ra`, `rb`, `rr`  
- Reverse rotate: `rra`, `rrb`, `rrr`

For small stacks (2–5 elements), the program uses specialized sort routines.  
For larger stacks, it partitions the stack using median values and inserts elements into their optimal position while minimizing total operations.

## Instructions

### Compilation

```bash
# Compile the program
make
Run the program
# Example with a small stack
./push_swap 4 67 3 87 23
#or as a string
./push_swap "4 67 3 87 23"

Verify with checker
# Using checker_linux to verify the output
ARG="4 67 3 87 23"          # Bash variable with stack values
./push_swap $ARG | ./checker_linux $ARG

Sort large stacks
# create a test file 
shuf -i 1-1000000 -n 500 > nums500.txt
# Example with 500 numbers stored in nums500.txt to check the number of operations
./push_swap $(cat nums500.txt) | wc -l


Resources
https://medium.com/@ayogun/push-swap-c1f5d2d41e97
https://github.com/AdrianWR/push_swap
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

I used ChatGpt mainly for research and to find mistakes.
