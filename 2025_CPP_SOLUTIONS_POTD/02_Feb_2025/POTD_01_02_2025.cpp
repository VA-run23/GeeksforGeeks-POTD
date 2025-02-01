class Solution {
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && dfs(mat, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index) {
        if (index == word.length()) {
            return true;
        }
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != word[index]) {
            return false;
        }

        char temp = mat[i][j];
        mat[i][j] = '*'; 

        bool found = dfs(mat, word, i + 1, j, index + 1) ||
                     dfs(mat, word, i - 1, j, index + 1) ||
                     dfs(mat, word, i, j + 1, index + 1) ||
                     dfs(mat, word, i, j - 1, index + 1);

        mat[i][j] = temp; 
        return found;
    }
};
