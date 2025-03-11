class Solution {
  public:
    int helper(int n, int x, vector<int> &dp ){
        if(n == x){
            return 1;
        }
        if(x>n){
            return 0;
        }
        if(dp[x]!= -1){
            return dp[x];
        }        
        dp[x] = helper(n, x+1, dp)+helper(n, x+2, dp);
        // dp[x] = dp[x]+dp[x+1];
        return dp[x];
    }
    int countWays(int n) {
        // your code here
            vector<int> dp(n+1, -1);
            int ans = helper(n, 0, dp);
            return ans;
    }
};