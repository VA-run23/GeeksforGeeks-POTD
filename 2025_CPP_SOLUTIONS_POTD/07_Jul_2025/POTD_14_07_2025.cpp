/*
    1. Initialize 'dp' with INF (an unattainable high value), where 'dp[i]' will store the minimum cuts needed from index 'i' to end; set 'dp[n] = 0' as base case.
    2. Precompute and store all powers of 5 (up to 2^30) in a set 'p5' for quick lookup of valid binary substrings.
    3. Traverse the string from right to left; skip index 'i' if 's[i]' is '0' since powers of 5 cannot have leading zeros.
    4. For each index 'i', iterate forward to form binary substrings ending at 'j', convert it to decimal 'num' using bit shifting.
    5. If 'num' exceeds 2^30, break early; otherwise, if 'num' is a power of 5 and 'dp[j+1]' is valid, try updating 'dp[i]' to minimum cuts.
    6. After filling the DP table, if 'dp[0]' is still INF, return -1 indicating no valid splitting; else return 'dp[0]'.
    7. Time complexity: O(n²) in worst case due to nested loops; Space complexity: O(n + m), where 'm' is the number of stored powers of 5.
*/


class Solution {
  public:
    int cuts(string &s) {
        // code here
        int n = s.size() , INF = n + 1;
        vector<int> dp(n + 1 , INF);
        dp[n] = 0;
        
        unordered_set<int> p5;
        for(long long x = 1; x <= (1LL << min(n , 30)); x *= 5)
        p5.insert(x);
        
        for(int i = n - 1 ; i >= 0 ; --i){
            if(s[i] == '0') continue;
            long long num = 0;
            for(int j = i ; j < n ; ++j){
                num = (num << 1) + (s[j] - '0');
                if(num > (1LL << 30)) break;
                if(p5.count(num) && dp[j + 1] != INF){
                    dp[i] = min(dp[i] , 1 + dp[j + 1]);
                }
            }
        }
        
        return dp[0] >= INF ? -1 : dp[0];
        
    }
};