// Count Matching Subsequences

/*
 *    1. The problem asks to count how many times string s2 occurs as a subsequence in string s1.
 *    2. A subsequence means characters appear in order but not necessarily contiguously.
 *    3. The recursive function explores two choices: match current characters or skip one in s1.
 *    4. Memoization is used to avoid recomputation of overlapping subproblems.
 *    5. Base cases handle when either string is fully traversed.
 *    6. Modulo 1e9+7 ensures results fit within integer limits.
 *    7. Time Complexity: O(n*m), Space Complexity: O(n*m) where n = s1 length, m = s2 length.
 */

class Solution {
  public:
    int mod = 1e9+7;
    int solve(int i,int j , string a, string b,vector<vector<int>>&dp){
        if(i >= a.size()){
            return j >= b.size();
        }
        if(j >= b.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = 0;
        if(a[i] == b[j]){
            ans += solve(i+1,j+1,a,b,dp);
        }
        ans += solve(i+1,j,a,b,dp);
        return dp[i][j] = ans%mod;
        
    }
    int countWays(string &s1, string &s2) {
        // code here
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(0,0,s1,s2,dp);
    }
};

// Key Points
// 1. Uses recursion with memoization to avoid repeated calculations.
// 2. Handles base cases carefully for subsequence completion.
// 3. Applies modulo to prevent overflow.
// 4. DP table size is (n+1)*(m+1).
// 5. Works efficiently for large strings due to memoization.
// 6. Counts all possible subsequences, not just contiguous matches.
// 7. Complexity is polynomial, making it feasible for competitive programming.