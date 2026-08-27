// Largest Rectangle with Column Swaps

/*
 *    1. The problem asks to find the largest rectangle of 1s in a binary matrix when column swaps are allowed.
 *    2. Build histogram heights for each row: hist[i][j] = consecutive 1s up to row i in column j.
 *    3. For each row, sort histogram heights in descending order.
 *    4. After sorting, the j-th height represents the maximum possible rectangle height if we take j+1 columns.
 *    5. Compute area = (j+1) * hist[i][j] for each row and column.
 *    6. Track maximum area across all rows.
 *    7. Time Complexity: O(r * c log c), Space Complexity: O(r * c).
 */

class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        int r = mat.size();
        if (r == 0) return 0;
        int c = mat[0].size();

        vector<vector<int>> hist(r, vector<int>(c, 0));
        for (int j = 0; j < c; j++) {
            hist[0][j] = mat[0][j];
        }
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1)
                    hist[i][j] = hist[i - 1][j] + 1;
                else
                    hist[i][j] = 0;
            }
        }

        for (int i = 0; i < r; i++) {
            sort(hist[i].begin(), hist[i].end(), greater<int>());
        }

        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ans = max(ans, (j + 1) * hist[i][j]);
            }
        }

        return ans;
    }
};

// Key Points
// 1. Builds histogram heights row by row.
// 2. Sorts each row to simulate column swaps.
// 3. After sorting, j-th height gives max rectangle with j+1 columns.
// 4. Computes area = (j+1) * height.
// 5. Tracks global maximum area.
// 6. Handles empty matrix case safely.
// 7. Runs in O(r * c log c) time with O(r * c) space.
