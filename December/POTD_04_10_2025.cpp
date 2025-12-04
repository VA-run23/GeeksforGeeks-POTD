/*
    1. This code solves the Optimal Binary Search Tree (OBST) problem using recursion + memoization (DP).
    2. The function 'recur(l, r, arr)' computes the minimum search cost for keys in range [l..r].
    3. Base cases: if l == r, return frequency of that single key; if l > r, return 0 (empty tree).
    4. Memoization: dp[l][r] stores already computed results to avoid redundant calculations.
    5. For each possible root k in [l..r], compute cost = left subtree + right subtree + sum of frequencies.
    6. The minimum cost among all choices of k is stored in dp[l][r] and returned.
    7. Time Complexity: O(n^3) (due to three nested loops in recursion with memoization); Space Complexity: O(n^2) for dp table.
*/

/* Key Points:
    - Problem: Construct an Optimal BST minimizing weighted search cost.
    - Approach: Recursion + DP (memoization).
    - Frequencies are summed to account for depth contribution of all nodes in subtree.
    - dp[l][r] ensures overlapping subproblems are solved once.
    - Complexity: O(n^3) time, O(n^2) space.
    - This is a classic DP problem; optimizations like Knuth’s can reduce time to O(n^2).
*/

class Solution {
public:
    int dp[101][101];
    int recur(int l, int r, vector<pair<int, int>>& arr) {
        if (l == r)
            return arr[l].second;
        if (l > r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int ans = INT_MAX, total_freq = 0;
        for (int i = l; i <= r; i++) {
            int cans = recur(l, i - 1, arr) + recur(i + 1, r, arr);
            ans = min(ans, cans);
            total_freq += arr[i].second;
        }
        return dp[l][r] = ans + total_freq;
    }
    int minCost(vector<int>& keys, vector<int>& freq) {
        // code here
        int n = keys.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = {keys[i], freq[i]};
        memset(dp, -1, sizeof(dp));
        return recur(0, n - 1, arr);
    }
};