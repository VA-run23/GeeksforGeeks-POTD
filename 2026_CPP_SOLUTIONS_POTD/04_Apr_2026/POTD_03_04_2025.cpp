// Print Diagonally

/*
 *    1. Each diagonal in a matrix can be identified by the sum of its indices (i + j).
 *    2. Elements with the same sum belong to the same diagonal.
 *    3. Use a map or vector of vectors to group elements by their diagonal index.
 *    4. Traverse the matrix and push each element into its corresponding diagonal bucket.
 *    5. After grouping, flatten the diagonals into the result vector in order.
 *    6. This avoids manual index resets and simplifies traversal logic.
 *    7. Time Complexity: O(n*m), Space Complexity: O(n*m) for storing diagonals.
 */

class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> diagonals(n + m - 1);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                diagonals[i + j].push_back(mat[i][j]);
            }
        }

        vector<int> ans;
        for(auto &d : diagonals) {
            for(auto &val : d) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};

// Key Points
// 1. Diagonals are identified by sum of indices (i + j).
// 2. Group elements into buckets based on diagonal index.
// 3. Traverse matrix once to fill buckets.
// 4. Flatten buckets into final result vector.
// 5. Simplifies logic compared to index-reset method.
// 6. Works for both square and rectangular matrices.
// 7. O(n*m) time and space complexity, efficient and clean.