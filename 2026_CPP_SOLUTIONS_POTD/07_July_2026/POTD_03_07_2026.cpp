// Ways to Increase LCS by One

/*
 *    1. Compute positions of each character in the second string.
 *    2. Build prefix LCS table (lcsl) using dynamic programming.
 *    3. Build suffix LCS table (lcsr) using reverse dynamic programming.
 *    4. Calculate base LCS length between the two strings.
 *    5. Try inserting each character at every position in the first string.
 *    6. Check if insertion increases LCS by exactly one.
 *    7. Time Complexity: O(n1 * n2 * M), Space Complexity: O(n1 * n2) where M = 26.
 */

class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        // code here
        int n1 = s1.length();
        int n2 = s2.length();
    
        int M = 26;
    
        vector<vector<int>> position(M);
    
        for (int i = 1; i <= n2; i++)
            position[s2[i - 1] - 'a'].push_back(i);
    
        vector<vector<int>> lcsl(n1 + 2, vector<int>(n2 + 2, 0));
        vector<vector<int>> lcsr(n1 + 2, vector<int>(n2 + 2, 0));
    
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1])
                    lcsl[i][j] = 1 + lcsl[i - 1][j - 1];
                else
                    lcsl[i][j] = max(lcsl[i - 1][j], lcsl[i][j - 1]);
            }
        }
    
        for (int i = n1; i >= 1; i--) {
            for (int j = n2; j >= 1; j--) {
                if (s1[i - 1] == s2[j - 1])
                    lcsr[i][j] = 1 + lcsr[i + 1][j + 1];
                else
                    lcsr[i][j] = max(lcsr[i + 1][j], lcsr[i][j + 1]);
            }
        }
    
        int ways = 0;
        int baseLCS = lcsl[n1][n2];
    
        for (int i = 0; i <= n1; i++) {
            for (char c = 'a'; c <= 'z'; c++) {
    
                vector<int> &posList = position[c - 'a'];
                for (int j = 0; j < (int)posList.size(); j++) {
                    int p = posList[j];
                    if (lcsl[i][p - 1] + lcsr[i + 1][p + 1] == baseLCS) {
                        ways++;
                        break;
                    }
                }
            }
        }
    
        return ways;
    }
};

// Key Points
// 1. Uses dynamic programming to compute LCS from both ends.
// 2. Prefix table (lcsl) stores LCS up to indices.
// 3. Suffix table (lcsr) stores LCS from indices to end.
// 4. Base LCS length is computed once.
// 5. Each insertion is checked against character positions in s2.
// 6. Valid insertions must increase LCS by exactly one.
// 7. Efficiently counts all possible valid insertions.