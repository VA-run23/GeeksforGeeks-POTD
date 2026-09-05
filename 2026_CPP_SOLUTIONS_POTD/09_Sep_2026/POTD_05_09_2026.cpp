// Longest Subsequence with Adjacent Difference = 1

/*
 *    1. The problem asks to find the length of the longest subsequence where the difference between adjacent elements is exactly 1.
 *    2. Use a hash map dp[x] to store the longest subsequence ending at value x.
 *    3. For each element x in arr:
 *       - Look at dp[x-1] and dp[x+1] (neighbors differing by 1).
 *       - Take the maximum of these as prev.
 *       - Update dp[x] = prev + 1.
 *    4. Track the global maximum length across all updates.
 *    5. This ensures subsequences are built dynamically without sorting.
 *    6. Works efficiently since each element is processed once.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : arr) {
            int prev = max(dp[x - 1], dp[x + 1]);
            dp[x] = prev + 1;
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};

// Key Points
// 1. Uses hash map to track subsequence lengths by value.
// 2. For each x, checks neighbors (x-1, x+1).
// 3. Updates dp[x] = max(dp[x-1], dp[x+1]) + 1.
// 4. Maintains global maximum subsequence length.
// 5. Avoids sorting or nested loops.
// 6. Efficient O(n) solution with O(n) space.
// 7. Elegant dynamic approach for adjacency difference constraint.