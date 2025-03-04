/* 
 * The `dpSol` function recursively calculates the LIS starting from index `i`.
 * It uses memoization with the `dp` array to store intermediate results.
 * The function `lis` initializes the `dp` array with -1 and iterates over all elements.
 * For each element, it calls `dpSol` to get the LIS ending at that element.
 * The `maxLen` variable keeps track of the maximum LIS found.
 * Finally, `lis` returns `maxLen` which is the length of the longest increasing subsequence.
 */

class Solution {
public:
    int dpSol(vector<int> &arr, int i, vector<int> &dp) {
        if (i >= arr.size()) return 0;
        
        if (dp[i] != -1) return dp[i];

        int len = 1;
        for (int j = i+1; j < arr.size(); ++j) {
            if (arr[j] > arr[i]) {
                len = max(len, 1 + dpSol(arr, j, dp));
            }
        }

        dp[i] = len;
        return dp[i];
    }

    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);
        
        int maxLen = 1;
        for (int i = 0; i < n; ++i) {
            maxLen = max(maxLen, dpSol(arr, i, dp));
        }

        return maxLen;
    }
}
;