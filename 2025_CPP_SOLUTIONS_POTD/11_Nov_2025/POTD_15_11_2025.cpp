/*
   1. The function 'minCutCost' calculates the minimum cost to cut a stick of length 'n' at given positions in 'cuts'.
   2. It first appends boundaries (0 and n) to the cuts array and sorts it to handle intervals properly.
   3. A 2D DP table 'dp[i][j]' is created where each entry stores the minimum cost to cut the stick between cuts[i] and cuts[j].
   4. The algorithm iterates over increasing interval lengths ('len') to fill the DP table bottom-up.
   5. For each interval [i, j], it tries all possible cut positions 'k' between i and j, computing cost as: 
      dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]).
   6. The minimum of all possible cut costs is stored in dp[i][j]; if no valid cut exists, it remains 0.
   7. Finally, dp[0][m+1] gives the minimum cost to cut the entire stick from 0 to n.
      → Time Complexity: O(m^3), since for each interval we try all possible cuts.
      → Space Complexity: O(m^2), due to the DP table storing results for all intervals.
*/

// Key Points:
// - Problem is solved using **interval DP** (dynamic programming on ranges).
// - Adding boundaries (0 and n) ensures the stick is fully covered.
// - Sorting cuts is crucial to maintain correct intervals.
// - The recurrence relation ensures optimal substructure: cost = left + right + current cut length.
// - This is similar to matrix chain multiplication or optimal BST problems in DP.

class Solution {
  public:
    int minCutCost(int n, vector<int>& cuts) {
        // code here
        int m = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m + 2, vector<int>(m + 2, 0));
        for (int len = 2; len < m + 2; len++) {
            for (int i = 0; i + len < m + 2; i++) {
                int j = i + len;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j],
                        dp[i][k] + dp[k][j] + cuts[j] - cuts[i]
                    );
                }
                if (dp[i][j] == INT_MAX) dp[i][j] = 0;
            }
        }
        return dp[0][m + 1];
    }
};