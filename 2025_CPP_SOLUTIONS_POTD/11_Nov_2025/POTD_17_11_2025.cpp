/*
    1. The function 'maxSumIS' computes the Maximum Sum Increasing Subsequence (MSIS) using dynamic programming.
    2. We create a 'dp' array where 'dp[i]' stores the maximum sum of an increasing subsequence ending at index 'i'.
    3. For each element 'arr[i]', we look at all previous elements 'arr[j]' (where j < i).
    4. If 'arr[i] > arr[j]', it means we can extend the subsequence ending at 'j' to include 'arr[i]'.
    5. We update 'best' as the maximum sum achievable before 'i', then set 'dp[i] = best + arr[i]'.
    6. The variable 'ans' keeps track of the overall maximum sum across all subsequences.
    7. Time Complexity = O(n^2) due to nested loops; Space Complexity = O(n) for the 'dp' array.
*/

class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int ans = 0,n = arr.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            int best = 0;
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    best = max(best,dp[j]);
                }
            }
            dp[i] = best+arr[i];
            ans= max(ans,dp[i]);
        }
        return ans;
    }
};