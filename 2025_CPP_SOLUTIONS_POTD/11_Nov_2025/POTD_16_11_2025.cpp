/*
    1. The function LCIS computes the Longest Common Increasing Subsequence (LCIS) between two arrays a[] and b[].
    2. It initializes a DP array of size m (length of b) where dp[j] stores the LCIS length ending at b[j].
    3. For each element a[i], it iterates through b[], maintaining currMx = maximum LCIS length for elements smaller than a[i].
    4. If a[i] == b[j], then dp[j] can be extended, so dp[j] = currMx + 1.
    5. If b[j] < a[i], update currMx = max(currMx, dp[j]) to track the best subsequence length so far.
    6. After processing all elements, the maximum value in dp[] represents the LCIS length.
    7. Time Complexity: O(n * m) since we traverse both arrays; Space Complexity: O(m) for the dp array.
*/

class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size(), m = b.size();
        vector<int> dp(m, 0);
        for (int i = 0; i < n; i++) {
            int currMx = 0;
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[j] = currMx + 1;
                }
                else if (b[j] < a[i]) {
                    currMx = max(currMx, dp[j]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};