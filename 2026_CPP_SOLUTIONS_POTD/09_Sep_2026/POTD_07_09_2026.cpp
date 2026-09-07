// Minimum Elements Outside Subsequences

/*
 *    1. The problem asks for the minimum number of elements not part of either an increasing or decreasing subsequence.
 *    2. Idea: try to partition the array into two subsequences (one increasing, one decreasing).
 *    3. Use recursion + memoization (DP) to explore possibilities.
 *    4. State parameters:
 *       - idx → current index in array
 *       - incLast → last index used in increasing subsequence
 *       - decLast → last index used in decreasing subsequence
 *    5. Transition:
 *       - Option 1: exclude current element → cost = 1 + solve(next)
 *       - Option 2: include in increasing subsequence if valid
 *       - Option 3: include in decreasing subsequence if valid
 *    6. Memoize results in dp[idx][incLast+1][decLast+1] to avoid recomputation.
 *    7. Time Complexity: O(n³), Space Complexity: O(n³).
 */

class Solution {
    int dp[105][105][105];

    int solve(int idx, int incLast, int decLast, vector<int>& arr) {
        if (idx == arr.size()) return 0;

        if (dp[idx][incLast + 1][decLast + 1] != -1)
            return dp[idx][incLast + 1][decLast + 1];

        // Option 1: exclude current element
        int ans = 1 + solve(idx + 1, incLast, decLast, arr);

        // Option 2: include in increasing subsequence
        if (incLast == -1 || arr[idx] > arr[incLast]) {
            ans = min(ans, solve(idx + 1, idx, decLast, arr));
        }

        // Option 3: include in decreasing subsequence
        if (decLast == -1 || arr[idx] < arr[decLast]) {
            ans = min(ans, solve(idx + 1, incLast, idx, arr));
        }

        return dp[idx][incLast + 1][decLast + 1] = ans;
    }

public:
    int minCount(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return solve(0, -1, -1, arr);
    }
};

// Key Points
// 1. Recursively explores inclusion/exclusion of each element.
// 2. Tracks last element of increasing and decreasing subsequences.
// 3. Exclusion adds +1 to cost.
// 4. Inclusion allowed only if subsequence condition holds.
// 5. Memoization ensures efficiency by caching states.
// 6. Handles edge cases with incLast/decLast = -1.
// 7. Runs in O(n³) time with O(n³) space.