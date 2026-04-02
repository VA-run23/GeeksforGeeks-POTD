// Painting the Fence

/*
 *    1. We are given n posts and k colors to paint them.
 *    2. The constraint is that no more than two adjacent posts can have the same color.
 *    3. For n = 1, the answer is simply k (any color can be chosen).
 *    4. For n = 2, the answer is k * k (both posts can be painted independently).
 *    5. For n >= 3, we use dynamic programming to track cases where the last two posts are same or different.
 *    6. Transition: same = diff (previous different case), diff = total * (k - 1), total = same + diff.
 *    7. Time Complexity: O(n), Space Complexity: O(1) since only constant variables are used.
 */

class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        if (n == 1) return k;
        if (n == 2) return k * 1LL * k;
    
        int same = k;
        int diff = k * (k - 1);
        int total = same + diff;
    
        for (int i = 3; i <= n; i++) {
            same = diff;
            diff = total * (k - 1);
            total = (same + diff); 
        }
        return total;
    }
};

// Key Points
// 1. Base cases for n = 1 and n = 2 are handled separately.
// 2. Dynamic programming avoids recomputation.
// 3. "same" tracks cases where last two posts are same.
// 4. "diff" tracks cases where last two posts are different.
// 5. Transition ensures no more than two adjacent posts are same.
// 6. Space optimized to O(1) using only three variables.
// 7. Efficient solution suitable for large n.