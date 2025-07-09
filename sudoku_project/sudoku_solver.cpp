#include <bits/stdc++.h>
using namespace std;

// Prints the board to stdout
void printBoard(const vector<vector<int>>& board) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cout << board[r][c] << " ";
        }
        cout << "\n";
    }
}

// Returns true if it's safe to place 'val' at board[row][col]
bool isSafe(const vector<vector<int>>& board,
            int row, int col,
            int val) {
    // 1) Check the row and column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == val) return false;
        if (board[i][col] == val) return false;
    }

    // 2) Check the 3x3 sub-grid
    // Determine the top-left corner of the sub-grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int r = startRow; r < startRow + 3; r++) {
        for (int c = startCol; c < startCol + 3; c++) {
            if (board[r][c] == val) return false;
        }
    }

    // If no conflicts, it's safe
    return true;
}

// Tries to solve the Sudoku using backtracking.
// Returns true if a solution is found.
bool solveSudoku(vector<vector<int>>& board,
                 int row = 0, int col = 0) {
    // If we've reached beyond the last row, the board is solved
    if (row == 9) {
        return true;
    }

    // Move to next row if we're past the last column
    if (col == 9) {
        return solveSudoku(board, row + 1, 0);
    }

    // Skip filled cells
    if (board[row][col] != 0) {
        return solveSudoku(board, row, col + 1);
    }

    // Try all possible values 1 through 9
    for (int val = 1; val <= 9; val++) {
        // Check if we can legally place 'val' here
        if (isSafe(board, row, col, val)) {
            board[row][col] = val;  // Place it

            // Recursively attempt to fill the rest
            if (solveSudoku(board, row, col + 1)) {
                return true;  // If it led to a solution, we're done
            }

            // Otherwise, backtrack
            board[row][col] = 0;
        }
    }

    // No valid number worked here → backtrack further
    return false;
}

int main() {
    // Example starting board: 0 denotes empty cells
    vector<vector<int>> board = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    cout << "Original puzzle:\n";
    printBoard(board);
    cout << "\nSolving...\n\n";

    if (solveSudoku(board)) {
        cout << "Solved puzzle:\n";
        printBoard(board);
    } else {
        cout << "No solution exists for this puzzle.\n";
    }

    return 0;
}
