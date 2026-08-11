// Largest Odd Square with Limited 1s

/*
 *    1. The problem asks to find the largest odd-length square centered at given query points with at most k ones inside.
 *    2. Use a prefix sum matrix to quickly compute the number of ones in any submatrix.
 *    3. Build prefix sums row by row and column by column to allow O(1) submatrix queries.
 *    4. For each query (i, j), expand outward symmetrically while checking the square sum with prefix sums.
 *    5. Stop expansion when the number of ones exceeds k or boundaries are crossed.
 *    6. The largest valid odd square size is (2*v - 1), where v is the expansion radius.
 *    7. Time Complexity: O(r·c + q·n) where r,c are matrix dimensions and q is number of queries, Space Complexity: O(r·c).
 */

class Solution {
public:
    vector<int> largestSquare(vector<vector<int>>& mat, vector<vector<int>>& queries, int k) {
        // code here
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> prefSum(r + 1, vector<int>(c + 1, 0));

        prefSum[1][1] = mat[0][0];
        for (int j = 1; j < c; j++)
            prefSum[1][j + 1] += mat[0][j] + prefSum[1][j];
        for (int i = 1; i < r; i++)
            prefSum[i + 1][1] += mat[i][0] + prefSum[i][1];

        for (int i = 1; i < r; i++)
            for (int j = 1; j < c; j++)
                prefSum[i + 1][j + 1] = prefSum[i][j + 1] + prefSum[i + 1][j] - prefSum[i][j] + mat[i][j];

        vector<int> res;
        for (auto it : queries) {
            int i = it[0] + 1;
            int j = it[1] + 1;
            int v = 0;
            while ((i + v <= r) && (i - v > 0) && (j + v <= c) && (j - v > 0)) {
                if (prefSum[i + v][j + v] - prefSum[i - v - 1][j + v] - prefSum[i + v][j - v - 1] + prefSum[i - v - 1][j - v - 1] > k)
                    break;
                v++;
            }
            res.push_back(2 * v - 1);
        }
        return res;
    }
};

// Key Points
// 1. Builds prefix sum matrix for O(1) submatrix queries.
// 2. Expands odd squares centered at query points.
// 3. Stops expansion when ones exceed k or boundaries fail.
// 4. Largest odd square size is (2*v - 1).
// 5. Efficiently handles multiple queries.
// 6. Runs in O(r·c + q·n) time.
// 7. Uses O(r·c) space for prefix sums.