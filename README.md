# Dynamic Tic Tac Toe (C)

A simple, beginner-friendly Tic Tac Toe game written in C. The board size and number of players are chosen at runtime so you can play on any square board (size > 2) with any number of players (> 1). The program reads moves, updates the board, and automatically checks for wins or a draw.

## Description
- Ask for board size (must be greater than 2).
- Ask for number of players (must be greater than 1).
- Players take turns entering moves in the format rowcol (first digit = row, second = column).
- The program detects and reports a win or a draw automatically.

Rows and columns are numbered starting at 1 up to the board size.

## How to play
1. Compile and run the program (instructions below).
2. Enter the board size (e.g., 3 for a 3×3 board).
3. Enter the number of players (e.g., 2).
4. Players take turns entering moves:
   - Type two digits with no spaces: the first is the row, the second is the column (for example, `11` = row 1, column 1).
   - Input must be within the board range and an empty cell.
5. The program prints the board after each move and stops when a player wins or the board is full (draw).

## Example (3×3, 2 players)
- Player 1 uses X, Player 2 uses O (typical display; the program will label each player's mark).
- Moves entered in order:
  1. Player 1 -> `11`
  2. Player 2 -> `12`
  3. Player 1 -> `21`
  4. Player 2 -> `22`
  5. Player 1 -> `31`  (Player 1 wins with a vertical line in column 1)

Board after Player 1's winning move:
```
[X] [O] [ ]
[X] [O] [ ]
[X] [ ] [ ]
```

## Compilation
You need a C compiler such as gcc or clang.

Compile:
gcc -std=c11 -O2 -Wall -Wextra -o tictactoe tictactoe.c

Run:
./tictactoe

Or just download the exe file

(If your compiler outputs a different binary name, run that binary instead, e.g., `./a.out`.)

Enjoy the game — it's a great way to practice C and basic game logic!
