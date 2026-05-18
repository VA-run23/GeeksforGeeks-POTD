// Maximum Sum Problem

/*
 *    1. The problem asks to maximize the sum by either keeping n or breaking it into n/2, n/3, and n/4.
 *    2. At each step, we decide whether to keep the number as-is or split it further.
 *    3. This is a recursive problem where overlapping subproblems occur.
 *    4. Memoization or dynamic programming can be used to optimize repeated calculations.
 *    5. Base case: if n equals 0, the maximum sum is 0.
 *    6. The recursive relation compares n with the sum of its split parts.
 *    7. Time Complexity: O(log n) with memoization; Space Complexity: O(log n) due to recursion stack.
 */

class Solution {
  public:
    int maxSum(int n) {
        // code here.
        if(n==0) return 0;
        int sum = max(n,max(n/2,maxSum(n/2)) + max(n/3,maxSum(n/3)) + max(n/4,maxSum(n/4)) );
        return sum;
    }
};

// Key Points
// 1. The problem is based on recursive decomposition.
// 2. Each number can either remain whole or be split into parts.
// 3. Overlapping subproblems make memoization essential for efficiency.
// 4. Without memoization, the solution may become exponential.
// 5. The base case ensures recursion terminates correctly.
// 6. The maximum is always taken between keeping n or splitting it.
// 7. Optimized solution uses a hash map or DP to store results.