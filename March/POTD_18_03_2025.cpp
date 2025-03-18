/*
1. This code determines if the array `arr` can be divided into two subsets with equal sums.
2. First, it calculates the total sum of all elements. If the total is odd, partitioning is impossible.
3. The target sum for each subset is half of the total sum. A dynamic programming (DP) approach is used.
4. The `dp` array keeps track of which sums can be formed using the elements of `arr`.
5. Initially, `dp[0]` is set to `true`, as a sum of 0 can always be achieved with an empty subset.
6. For each element in `arr`, it updates the `dp` array, checking if current or previous sums can lead to the target.
7. Finally, it returns whether the target sum can be achieved (`dp[target]`).
*/

class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        int n = arr.size();

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
