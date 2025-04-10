# Sudoku Solver in C

A fully functional Sudoku puzzle generator and solver written in C.
- Implements a recursive backtracking algorithm
- Multiple difficulty levels with unique solutions


## Rules
    - Each row must contain numbers 1–9 with no repeats.
    - Each column must contain numbers 1–9 with no repeats.
    - Each 3×3 sub-grid must contain numbers 1–9 with no repeats.

Board is represented as 9x9 grid in a 2d array

---
### File Structure
```sh
.
├── generator.c
├── solver.c
├── sudoku.h
└── README.md
└── notes.md
```
### Compilation
```sh
gcc solver.c generator.c -o sudoku
```
```sh 
Note: only two arguments medium and hard
- medium is default if no argument provided
```

### Execution
```sh
./sudoku [medium|hard]
```

---
## Future Features (Extensions)
- Visualize the solving process step-by-step (console or GUI).
- Allow user input (enter puzzle manually) or using .txt file.
- Export the solved puzzle.
- solve soduku using parallelization
    ## For Future optimization
    - Add heuristics:
        -   MRV (Minimum Remaining Values): Choose cells with the fewest valid options first.
        - Forward Checking: Eliminate choices for neighboring cells.
    - Profile your code, see where the most time is spent.