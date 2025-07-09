# 🧠 Sudoku Solver: A Demonstration of Recursion & Backtracking

This Sudoku Solver project exemplifies the practical application of recursion and backtracking to efficiently solve one of the world's most celebrated logic puzzles. Designed for both browser-based interaction and terminal execution, this repository provides a robust, industry-ready implementation that highlights core algorithmic concepts and clean software architecture.

---

## 🚀 Project Overview

- **Recursive Problem Decomposition:** Systematically breaking down the Sudoku grid into manageable subproblems, each addressed through recursive calls.
- **Backtracking:** Ensuring that invalid choices are efficiently retracted, allowing the algorithm to explore alternative solution paths.
- **Data Structure Manipulation:** Leveraging 2D arrays to represent and update the board state with minimal computational overhead.
- **API Integration:** Fetching real-time puzzles to demonstrate practical, extensible code.

---

## 🧩 Project Structure

The repository includes both a **web-based interface** and a **C++ terminal implementation**, each designed to showcase the underlying logic and enhance user experience.

### 1. `index.html` — User Interface

- **Purpose:** Defines the 9x9 Sudoku grid and interactive controls.
- **Implementation:** Each cell is a uniquely identified `<div>`, forming a grid that directly maps to the JavaScript 2D array.
- **User Interaction:** Two primary buttons—**GetPuzzle** and **SolvePuzzle**—allow users to fetch a new puzzle or initiate the solving process.

### 2. `style.css` — Visual Design

- **Purpose:** Provides a visually appealing and intuitive Sudoku board.
- **Implementation:** Utilizes CSS classes for color-coding subgrids, emphasizing borders, and styling interactive elements for a modern user experience.
- **Outcome:** Ensures the application is both functional and visually engaging.

### 3. `script.js` — Core Logic

- **Purpose:** Implements the Sudoku solving algorithm using recursion and backtracking.
- **Key Features:**
  - **Grid Mapping:** Associates each HTML cell with a corresponding element in a 2D JavaScript array for seamless data manipulation.
  - **API Integration:** Retrieves random puzzles from [sugoku.onrender.com](https://sugoku.onrender.com) via AJAX requests.
  - **Algorithmic Engine:** The `sudukoSolver` function recursively fills the board, employing backtracking to resolve conflicts and ensure a valid solution.
  - **UI Synchronization:** Dynamically updates the grid to reflect the current state of the solution process.

---

## 🌐 API Integration Details

- **GetPuzzle:**  
  Clicking the `GetPuzzle` button triggers an AJAX GET request to the Sugoku API:

  ```sh
  curl "https://sugoku.onrender.com/board?difficulty=easy"
  ```

  The API responds with a new Sudoku puzzle (as a 2D array), which is then rendered on the grid for user interaction.

- **SolvePuzzle:**  
  Selecting `SolvePuzzle` invokes the `sudukoSolver` function, which:
  1. **Recursively** attempts to fill each empty cell with a valid number.
  2. **Backtracks** upon encountering conflicts, retracting previous moves and exploring alternative options.
  3. **Updates** the UI in real time, providing clear visual feedback of the solving process.

---

## 🖥️ C++ Terminal Implementation

The repository also includes a terminal-based solver (`sudoku_solver.cpp`). This version employs the same recursive backtracking logic, demonstrating the universality and portability of these algorithmic techniques across different programming environments.

**Compile and run the C++ version:**
```sh
g++ sudoku_solver.cpp -o sudoku_solver
./sudoku_solver
```

---

## 🧠 Key Learning Outcomes

- **Recursion:** Master the art of decomposing complex problems into smaller, self-similar tasks.
- **Backtracking:** Learn to systematically explore and retract decisions within a constrained search space.
- **Data Structures:** Understand how 2D arrays can effectively model and manipulate grid-based puzzles.
- **API Integration:** Gain experience in fetching and processing data from external sources in real time.
- **UI Synchronization:** Discover best practices for keeping the user interface in sync with underlying algorithmic operations.

---

## 🛠️ Getting Started

1. **Clone the Repository**
   ```sh
   git clone https://github.com/ritvik412/sudoku_solver.git
   cd sudoku_solver
   ```

2. **Run the Web Version**
   - Open `index.html` directly in your preferred browser, or
   - For full AJAX support, run a local server:
     ```sh
     python3 -m http.server
     # Then open http://localhost:8000 in your browser
     ```

3. **Run the C++ Version**
   ```sh
   g++ sudoku_solver.cpp -o sudoku_solver
   ./sudoku_solver
   ```

---

## 🤝 Final Thoughts

This project is more than just code—it is a professional showcase of algorithmic thinking and software design. By exploring recursion and backtracking in the context of Sudoku, you will gain a deep understanding of how advanced algorithms can be applied to solve complex, real-world problems efficiently and elegantly.

