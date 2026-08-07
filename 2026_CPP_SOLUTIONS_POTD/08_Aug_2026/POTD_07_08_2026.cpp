// Friends Pairing Problem

/*
 *    1. The problem asks to count the number of ways n friends can remain single or be paired up.
 *    2. Each friend has two choices: stay single or pair with one of the remaining friends.
 *    3. Recurrence relation: f(n) = f(n-1) + (n-1) * f(n-2).
 *    4. f(n-1) covers the case when the nth friend stays single.
 *    5. (n-1) * f(n-2) covers the case when the nth friend pairs with one of the (n-1) others.
 *    6. Memoization ensures overlapping subproblems are computed only once.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    vector<int> dp;
    int solve(int n) {
        if (dp[n] != -1)
            return dp[n];
        
        return dp[n] = solve(n - 1) + (solve(n - 2) * (n - 1));
    }
    int countFriendsPairings(int n) {
        // code here
        dp = vector<int>(n + 1, -1);
        dp[0] = dp[1] = 1;
        return solve(n);
    }
};

// Key Points
// 1. Uses recursion with memoization to avoid recomputation.
// 2. Recurrence relation f(n) = f(n-1) + (n-1)*f(n-2).
// 3. f(n-1) handles nth friend staying single.
// 4. (n-1)*f(n-2) handles nth friend pairing.
// 5. Base cases: f(0) = 1, f(1) = 1.
// 6. Runs in O(n) time with O(n) space.
// 7. Classic dynamic programming problem with combinatorial interpretation.