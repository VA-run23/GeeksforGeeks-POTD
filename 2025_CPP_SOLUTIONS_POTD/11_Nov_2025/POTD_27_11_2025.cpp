/*
    1. The function 'solve' recursively explores all subsets of the array by either including (take) or excluding (notTake) the current element, updating the XOR value accordingly.
    2. When the recursion reaches the end of the array ('i == arr.size()'), it returns the XOR value of that subset, contributing to the total sum.
    3. A memoization table 'dp[i][Xor]' is used to store results of subproblems, avoiding recomputation and improving efficiency.
    4. The 'subsetXORSum' function initializes the DP table and calls 'solve' starting with XOR = 0 and index = 0.
    5. The DP table size is '(n+1) x (2001)' because XOR values can range up to about 2000, ensuring all possible states are covered.
    6. Time Complexity: O(n * maxXor) where maxXor ≈ 2000, since each state (i, Xor) is computed once; Space Complexity: O(n * maxXor) due to the DP table.
    7. This approach ensures all subsets are considered efficiently, and the sum of XORs of all subsets is returned.
*/

/* Key Points : 
- Each element of a set of size n appears in exactly 2^(n-1) subsets.
- This property is crucial in XOR problems: the contribution of each bit can be calculated directly using this count.
- The recursive + DP solution here explicitly enumerates subsets but avoids recomputation.
- Alternatively, a direct formula exists: total XOR sum = (bitwise OR of all elements) * 2^(n-1).
- The DP approach is more general and demonstrates subset exploration, while the formula is optimized.
*/

class Solution {
  public:
    int solve(vector<int> &arr, int Xor, int i,vector<vector<int>> &dp){
        if(i == arr.size()){
            return Xor;
        }
        if(dp[i][Xor] != -1)
            return dp[i][Xor];
        int take    = solve(arr,Xor^arr[i],i+1, dp);
        int notTake = solve(arr,Xor,i+1, dp);
        return dp[i][Xor] = take + notTake;
    }
    
    int subsetXORSum(vector<int>& arr){
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2e3+1, -1));
        return solve(arr,0,0,dp);
    }
};