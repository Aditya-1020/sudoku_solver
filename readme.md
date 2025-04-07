program a sudoku solver in C

## Rules
    - Each row must contain numbers 1–9 with no repeats.
    - Each column must contain numbers 1–9 with no repeats.
    - Each 3×3 sub-grid must contain numbers 1–9 with no repeats.

Board is represented as 9x9 grid in a 2d array
- Create a data structure to represent the board (2D array or nested list).

## Generate Sudoku Puzzle
- Create a complete valid Sudoku board.
    - Include three difficulty modes which can be random based of a button press since a computer is solving:
        - Easy :Remove fewer numbers
        - Medium: Remove moderate number of numbers
        - Hard: Remove more numbers ensuring fewer clues
- ensure generated puzzle has a unique solution
- Validate that the puzzle has a unique solution after removing numbers.

## Add functionality to:
- print the board
- check if move is valid
- identify empty cells

## Implement the Solver Logic (Backtracking)
Use a recursive approach:
1. Find an empty cell.
2. Try numbers 1 to 9.
3. For each number, check if it’s valid.
    - If valid, place the number and recurse.
    - If the recursion leads to a dead end, backtrack (undo the number).
4. If the board is full, you're done.

Optional: Try iterative approaches later.

## Testing
- Hardcode a few Sudoku puzzles for testing.
- Try easy, medium, and hard puzzles (you can find these online).
- Ensure the solver completes each one correctly.

## Add Features (Extensions)
- Timer to measure solving time.
- Visualize the solving process step-by-step (console or GUI).
- Allow user input (enter puzzle manually).
- Add a difficulty estimator (count clues, analyze branching factor).
- Export the solved puzzle.
- solve soduku using parallelization


## Optimize
- Add heuristics:
    -   MRV (Minimum Remaining Values): Choose cells with the fewest valid options first.
    - Forward Checking: Eliminate choices for neighboring cells.
- Profile your code, see where the most time is spent.
---

### Backtracking workings
1. choose a point
2. check if it leads to a valid state
3. if yes move to next step
4. if no backtack (undo the choice) try next option

applying this to our sudoku with empy squares at places (solver.c)
- Enter cell
    - if empty cell
        - place digits from 1->9 one by one
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

generating the puzzle (generator.c)
for (looping around the array):
    if (cell[i][j] == 0):
        num = random_number() // generates random int between 1 and 9
            if (num != sudo_conditons)
                - these conditons check:
                    - n not in same row
                    - n not in same col
                    - n not is same 3x3 block
            if valid:
                cell[i][j] == num
    
    move to next cell


// im stuck at how you check for 3x3 block conditon ??


```sh
backtrack(state):
    if state is a solution:
        return true
    for choice in valid_choices(state):
        make the choice
        if backtrack(new_state):
            return true
        undo the choice
    return false
```