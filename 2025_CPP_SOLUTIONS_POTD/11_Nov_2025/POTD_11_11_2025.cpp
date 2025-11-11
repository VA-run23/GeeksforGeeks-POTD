/*
    1. This function computes the length of the shortest common supersequence (SCS) of two strings s1 and s2.  
    2. It uses dynamic programming to first calculate the length of the longest common subsequence (LCS).  
    3. A 2D DP table 'dp' of size (s1.size()+1) x (s2.size()+1) is created, initialized with 0.  
    4. For each character pair (s1[i-1], s2[j-1]), if they match, dp[i][j] = dp[i-1][j-1] + 1.  
    5. If they don’t match, dp[i][j] = max(dp[i-1][j], dp[i][j-1]), ensuring the longest subsequence is tracked.  
    6. After filling the table, dp[s1.size()][s2.size()] holds the length of the LCS.  
    7. The final answer is s1.size() + s2.size() - LCS, since SCS length = sum of lengths - LCS length.  

    Time Complexity: O(n * m), where n = s1.size() and m = s2.size().  
    Space Complexity: O(n * m), due to the 2D DP table.  
*/

class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        // code here
        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,0));
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return s1.size()+s2.size()-dp[s1.size()][s2.size()];
    }
};