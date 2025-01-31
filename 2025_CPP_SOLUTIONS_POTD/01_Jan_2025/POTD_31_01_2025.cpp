class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isSafe(vector<vector<int>>& mat, int row, int col, int num) {
        for (int x = 0; x < 9; x++) {
            if (mat[row][x] == num || mat[x][col] == num ||
                mat[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
                return false;
            }
        }
        return true;
    }

    bool solveSudokuUtil(vector<vector<int>>& mat, int row, int col) {
        // code here
        if (row == 8 && col == 9) {
            return true;
        }
        if (col == 9) {
            row++;
            col = 0;
        }
        if (mat[row][col] != 0) {
            return solveSudokuUtil(mat, row, col + 1);
        }
        for (int num = 1; num <= 9; num++) {
            if (isSafe(mat, row, col, num)) {
                mat[row][col] = num;
                if (solveSudokuUtil(mat, row, col + 1)) {
                    return true;
                }
                mat[row][col] = 0;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<int>>& mat) {
        solveSudokuUtil(mat, 0, 0);
    }
};