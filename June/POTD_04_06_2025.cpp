/*
    1. Get the lengths of the three input strings and initialize a 3D DP table.
    2. Iterate through each index of the three strings using nested loops.
    3. If the current characters of all three strings match, extend the LCS length.
    4. Otherwise, take the maximum LCS found by excluding one character at a time.
    5. Store the results in the DP table to avoid redundant calculations.
    6. Continue updating the table until all positions are processed.
    7. Return the final LCS length stored in dp[n1][n2][n3].
*/

class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        // code here
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, 0)));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                for (int k = 1; k <= n3; k++) {
                    if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) {
                        dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                    } else {
                        dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                    }
                }
            }
        }

        return dp[n1][n2][n3];
    }
};
