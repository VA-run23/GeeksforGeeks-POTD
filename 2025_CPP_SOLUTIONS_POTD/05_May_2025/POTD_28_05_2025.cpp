/*
    1. The function ValidCorner takes a 2D matrix 'mat' and checks if there exists a rectangle whose four corners are all 1s.
    2. First, it determines the number of rows (m) and columns (n). If either is less than 2, a rectangle is impossible, so it returns false.
    3. It iterates through each row and finds pairs of columns (j, k) where both positions have a 1.
    4. Whenever such a pair is found, it checks all previous rows to see if the same column indices (j, k) also contain 1s.
    5. If a previous row has 1s at both positions (j, k), a rectangle is formed, and the function immediately returns true.
    6. If no such rectangle is found after checking all possibilities, the function returns false.
    7. The approach efficiently scans the matrix, ensuring the condition is met while minimizing unnecessary checks.
*/
class Solution {
public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        if (m < 2 || n < 2) {
            return false;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (mat[i][j] == 1) {
                    for (int k = j + 1; k < n; k++) {
                        if (mat[i][k] == 1) {
                            // Check if any previous row has 1s at both columns j and k
                            for (int r = 0; r < i; r++) {
                                if (mat[r][j] == 1 && mat[r][k] == 1) {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }

        return false;
    }
};