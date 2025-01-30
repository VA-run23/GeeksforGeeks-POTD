class Solution {
public:
    // code here
    bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
        for (int i = 0; i < row; i++)
            if (board[i][col] == 1)
                return false;
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;
        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 1)
                return false;
        return true;
    }

    void solveNQueens(vector<vector<int>>& board, int row, int n, vector<vector<int>>& result) {
        if (row == n) {
            vector<int> currentSolution;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == 1) {
                        currentSolution.push_back(j + 1); 
                    }
                }
            }
            result.push_back(currentSolution);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 1;
                solveNQueens(board, row + 1, n, result);
                board[row][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> result;
        solveNQueens(board, 0, n, result);
        return result;
    }
};