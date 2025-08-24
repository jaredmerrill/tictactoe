# Tic-Tac-Toe in C

A simple console-based **Tic-Tac-Toe game** written in C.  
The player (`X`) competes against a computer opponent (`O`).  
The computer uses basic strategy to win or block the player’s moves, and falls back to random placement if no immediate moves are available.

---

## 🎮 How It Works
- The board is a 3x3 grid initialized with `-`.
- Players enter their move by typing a row and column (e.g., `1,2`).
- The computer checks:
  1. If it can win in the next move → it plays that move.
  2. If the player is about to win → it blocks the move.
  3. Otherwise → it places a piece randomly in an open spot.
- The game ends when either side wins or no spaces remain (tie).

---

## 🛠 Features
- Console-based UI with clear board printing.
- Input handling with row/column entry.
- Simple AI opponent with blocking/winning strategy.
- Tie detection and win announcements.

---

## ▶️ Compile & Run

Make sure you have a C compiler installed (e.g., `gcc`).

```bash
# Compile
gcc tictactoe.c -o tictactoe

# Run
./tictactoe

