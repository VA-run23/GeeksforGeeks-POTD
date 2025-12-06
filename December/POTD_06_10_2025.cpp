

/*
    1. This function solves the "Optimal Strategy for a Game" problem using dynamic programming with tabulation.
    2. dp[i][j] stores the maximum amount a player can collect from subarray arr[i...j] when both players play optimally.
    3. Base case: when i == j, only one coin remains, so dp[i][i] = arr[i].
    4. For each subarray length (len), we compute dp[i][j] by considering two choices: pick left coin or pick right coin.
    5. If the player picks arr[i], the opponent plays optimally, so we add arr[i] + min(dp[i+2][j], dp[i+1][j-1]).
    6. If the player picks arr[j], the opponent plays optimally, so we add arr[j] + min(dp[i][j-2], dp[i+1][j-1]).
    7. Finally, dp[0][n-1] gives the maximum amount the first player can secure. Time Complexity: O(n^2), Space Complexity: O(n^2).
*/

class Solution {
public:
    int maximumAmount(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = arr[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                int pickL = arr[i] + min(
                    (i + 2 <= j ? dp[i + 2][j] : 0),
                    (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0)
                );

                int pickR = arr[j] + min(
                    (i <= j - 2 ? dp[i][j - 2] : 0),
                    (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0)
                );

                dp[i][j] = max(pickL, pickR);
            }
        }

        return dp[0][n - 1];
    }
};