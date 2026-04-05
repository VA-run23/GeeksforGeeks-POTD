// Target Sum Problem

/*
 *    1. Given an array of integers, assign + or - signs to each element.
 *    2. The goal is to check how many ways the sum can equal the target.
 *    3. Use recursion with memoization to avoid recomputation.
 *    4. At each step, either add or subtract the current element.
 *    5. Base case: when all elements are processed, check if sum == target.
 *    6. Memoize results using dp[i][sum] to store subproblem answers.
 *    7. Time Complexity: O(n * sumRange), Space Complexity: O(n * sumRange)
 */

class Solution {
  public:
    int ans=0;
    int n;
    int dp[51][1001];
    
    int solve(vector<int>& arr, int target, int i, int sum){
        if(i==n){
            if(sum == target) return 1;
            return 0;
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        return dp[i][sum] = solve(arr, target, i+1, sum+arr[i]) + solve(arr, target, i+1, sum-arr[i]);
    }
    
    int totalWays(vector<int>& arr, int target) {
        //  code here
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        
        return solve(arr, target, 0, 0);
       
    }
};

// Key Points
// 1. Problem reduces to subset sum with signs.
// 2. Recursion explores both + and - choices.
// 3. Memoization avoids repeated calculations.
// 4. dp[i][sum] stores results for index and sum.
// 5. Base case checks if sum == target.
// 6. Works efficiently for small constraints.
// 7. Alternative DP approach can optimize further.