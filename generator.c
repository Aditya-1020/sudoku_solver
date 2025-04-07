/*
setup empty baord = {0}

input number n, position(row,col)
    check:
        - n not in same row
        - n not in same col
        - n not is same 3x3 block


Recursive fill function (backtracking)
- Find the next empty cell (0)
- Try placing numbers 1–9 in random order
- For each number:
    - If valid (use the validator), place it
    - Recursively call the fill function for the next cell
    - If that call fails (dead end), undo (backtrack) the current number and try the next
- If all numbers fail, return failure to backtrack
- If no empty cells are left, return success

*/