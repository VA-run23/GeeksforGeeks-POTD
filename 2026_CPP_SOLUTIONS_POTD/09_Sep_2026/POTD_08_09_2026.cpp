// Find the String in Grid

/*
 *    1. The problem asks to find all starting positions of a given word in a character grid.
 *    2. The word can appear in any of 8 directions (horizontal, vertical, diagonal).
 *    3. For each cell, if it matches the first character of the word, explore all 8 directions.
 *    4. Check bounds and character matches while traversing in a direction.
 *    5. If the word is found in any direction, record the starting position.
 *    6. Collect all valid positions and sort them for consistent output.
 *    7. Time Complexity: O(n * m * 8 * |word|), Space Complexity: O(1).
 */

class Solution {
public:
    bool searchDir(vector<vector<char>>& mat, int r, int c, string &word, int dr, int dc) {
        int n = mat.size(), m = mat[0].size();
        for (int k = 0; k < word.size(); k++) {
            int nr = r + dr * k;
            int nc = c + dc * k;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m || mat[nr][nc] != word[k]) 
                return false;
        }
        return true;
    }

    vector<vector<int>> searchWord(vector<vector<char>> &mat, string &word) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans;

        vector<int> dx = {-1,-1,-1,0,0,1,1,1};
        vector<int> dy = {-1,0,1,-1,1,-1,0,1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) {
                    for (int d = 0; d < 8; d++) {
                        if (searchDir(mat, i, j, word, dx[d], dy[d])) {
                            ans.push_back({i, j});
                            break; 
                        }
                    }
                }
            }
        }

        sort(ans.begin(), ans.end()); 
        return ans;
    }
};

// Key Points
// 1. Word can appear in 8 directions from any cell.
// 2. searchDir checks validity of word in a given direction.
// 3. Bounds checked to avoid out-of-grid access.
// 4. If match found, record starting position.
// 5. Sorting ensures consistent output order.
// 6. Efficiently explores only relevant directions.
// 7. Runs in O(n * m * |word|) time with O(1) extra space.