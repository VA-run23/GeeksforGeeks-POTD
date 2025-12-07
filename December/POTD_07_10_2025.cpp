/*
    1. We use dp[i] to store the number of distinct subsequences using the first i characters of the string.
    2. Each new character doubles the subsequences because every old subsequence can either include or exclude it.
    3. To avoid counting duplicates, we subtract the subsequences counted before the previous occurrence of the same character.
    4. The array prev[] stores the last index where each character appeared to help remove duplicate contributions.
    5. dp[0] = 1 represents the empty subsequence, which is always counted.
    6. The final answer dp[n] gives the total distinct subsequences modulo 1e9+7.
    7. Time Complexity: O(n), Space Complexity: O(n) due to dp[] and prev[] arrays.
*/

class Solution {
  public:
    int distinctSubseq(string &str) {
        // code here
        int MOD = 1e9 + 7;
        int n = str.length();
        vector <int> dp(n+1);
        vector <int> prev(26, -1);
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++){
            int curr = str[i-1] - 'a';
            dp[i] = (2LL * dp[i-1]) % MOD;
            
            if(prev[curr] != -1){
                dp[i] = (dp[i] - dp[prev[curr]] + MOD) % MOD;
            }
            
            prev[curr] = i - 1;
        }
        
        return dp[n];
    }
};