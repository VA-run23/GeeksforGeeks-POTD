// Count Derangements

/*
 *    1. A derangement is a permutation with no fixed points.
 *    2. In other words, no element appears in its original position.
 *    3. The recurrence relation is: D(n) = (n-1) * (D(n-1) + D(n-2)).
 *    4. Base cases: D(0) = 1, D(1) = 0.
 *    5. This recurrence can be solved iteratively using dynamic programming.
 *    6. We use two variables to store previous results and update them.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
public:
    int derangeCount(int n) {
        // code here
        if (n == 0)
            return 1;
        if (n == 1)
            return 0;
        int prev2 = 1;
        int prev1 = 0;
        int curr;
        for (int i = 2; i <= n; i++) {
            curr = (i - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};

// Key Points
// 1. Derangements count permutations with no element in its original place.
// 2. Recurrence relation: D(n) = (n-1) * (D(n-1) + D(n-2)).
// 3. Base cases are D(0)=1 and D(1)=0.
// 4. Iterative DP avoids recursion overhead.
// 5. Only two variables are needed for space optimization.
// 6. Efficient for large n due to O(n) time and O(1) space.
// 7. Can be extended to modular arithmetic for very large results.