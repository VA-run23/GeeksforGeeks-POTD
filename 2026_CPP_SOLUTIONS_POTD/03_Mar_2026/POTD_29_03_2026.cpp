// Partitions with Given Difference

/*
 *    1. We need to partition the array into two subsets such that their difference equals the given value.
 *    2. The problem reduces to finding subsets with a target sum derived from total sum and difference.
 *    3. If (sum - diff) is odd or sum < diff, no valid partition exists.
 *    4. The target sum becomes (sum - diff) / 2, which transforms the problem into subset sum counting.
 *    5. A recursive + memoization approach is used to count subsets achieving the target sum.
 *    6. Dynamic programming table stores intermediate results to avoid recomputation.
 *    7. Time Complexity: O(n * target), Space Complexity: O(n * target)
 */

class Solution {
public:
    virtual int fun(int i, int tar, vector<int>& arr, vector<vector<int>>& dp) {
        if (i < 0) {
            if (tar == 0)
                return 1;
            return 0;
        }

        if (dp[i][tar] != -1)
            return dp[i][tar];

        int t = 0, nt = 0;
        if (arr[i] <= tar)
            t = fun(i - 1, tar - arr[i], arr, dp);
        nt = fun(i - 1, tar, arr, dp);

        return dp[i][tar] = t + nt;
    }

    virtual int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for (int x : arr)
            sum += x;

        if (sum < diff || (sum - diff) % 2)
            return 0;

        int tar = (sum - diff) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(tar + 1, -1));
        return fun(n - 1, tar, arr, dp);
    }
};

// Key Points
// 1. Problem reduces to subset sum counting.
// 2. Target sum is derived from total sum and difference.
// 3. Recursive + memoization avoids redundant calculations.
// 4. Base case ensures valid partitions only when target is zero.
// 5. DP table ensures efficient computation.
// 6. Handles edge cases like odd (sum - diff) or sum < diff.
// 7. Optimizable further using 1D DP for space reduction.