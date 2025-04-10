#### Learnings and Findings
- added include gaurds crazy stuff..!
- prevents multiple inclusions of same file
    - basically checks if header is not defined.. define it now so nex time its included it tells the compiler its been handled
- like a fly swatter if its included already lol
- also used fisher yates shuffle cause i had a hard time creating unique boards

yeah so diffculties when generating can be selected like during the execution ussing command line arguments when executing the default will be medium diffculty
- two diff are:
    - medium: removes 36-46 digits
    - hard: removes 51-57 digits

- future note: learn to comment more after a week this seems foreign for some time
- damn im so smart reused a whole ass function (is_valid) in solver.c
- apparently you have to remove function in the other .c file and just have one main in a file here for me its solver.c which does every function call
- hardest thing has to be implemnting is_valid function

---

### Backtracking workings
1. choose a point
2. check if it leads to a valid state
3. if yes move to next step
4. if no backtack (undo the choice) try next option

applying this to our sudoku with empy squares at places (solver.c)
- Enter cell
    - if empty cell
        - try place digits from 1->9 one by one
            - for each checking if placed
                - not in same row
                - not in same col
                - not in same 3x3 grid
            - if valid
                - temporarily place the number
                - recursively move to next empty cell
                - if dead end undo the placement (backtrack) and try next number
            - if none fit
                - backtrack to previous try different number

---
function generate_board():
    for i in 0 to 8:
        for j in 0 to 8:
            if cell[i][j] == 0:
                nums = random_number(1..9)
                for num in nums:
                    if is_valid(i, j, num):
                        cell[i][j] = num
                        if generate_board(): // recursively go to next cell
                            return true
                        cell[i][j] = 0 // backtrack
                return false // no valid number found
    return true // board is filled


-- is_valid structure --
for k in 0 to 8:
    if cell[i][k] == num: return false // row check
    if cell[k][j] == num: return false // col check

startRow = (i // 3) * 3
startCol = (j // 3) * 3
for r in startRow to startRow+2:
    for c in startCol to startCol+2:
        if cell[r][c] == num: return false

return true

// im stuck at how you check for 3x3 block conditon ??
