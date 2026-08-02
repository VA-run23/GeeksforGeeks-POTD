// Sequences where Adjacent Divide

/*
 *    1. The problem asks to count sequences of length n using numbers from 1 to m where adjacent elements divide each other.
 *    2. A recursive relation is used: at each step, choose a number i such that it divides or is divisible by the previous number.
 *    3. Memoization (dp table) avoids recomputation of overlapping subproblems.
 *    4. Base case: when count == n, a valid sequence is formed, return 1.
 *    5. Transition: for each candidate i in [1..m], check divisibility with last and recurse.
 *    6. dp[last][count] stores the number of valid sequences starting with 'last' at position 'count'.
 *    7. Time Complexity: O(n · m²), Space Complexity: O(n · m).
 */

class Solution {
  public:
    int solve(int n,int m,int last,int count,vector<vector<int>>&dp){
        if(count==n){
            return 1;
        }
        if(dp[last][count]!=-1){
            return dp[last][count];
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            if(last%i==0 || i%last==0){
                ans+=solve(n,m,i,count+1,dp);
            }
        }
        return dp[last][count]=ans;
    }
    int count(int n, int m) {
        // code here
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(n,m,1,0,dp);
    }
};

// Key Points
// 1. Uses recursion with memoization to count valid sequences.
// 2. Base case returns 1 when sequence length reaches n.
// 3. Transition checks divisibility between adjacent elements.
// 4. dp[last][count] stores computed states to avoid recomputation.
// 5. Iterates over all possible next elements from 1 to m.
// 6. Ensures adjacent elements divide each other in both directions.
// 7. Runs in O(n · m²) time with O(n · m) space.