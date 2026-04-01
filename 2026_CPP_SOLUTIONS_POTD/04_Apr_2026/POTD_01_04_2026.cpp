// Consecutive 1's Not Allowed

/*
 *    1. The problem asks to count binary strings of length n without consecutive 1s.
 *    2. This can be solved using dynamic programming or Fibonacci-like recurrence.
 *    3. Let a represent count of strings ending with 0, and b represent count ending with 1.
 *    4. Transition: new strings ending with 0 = previous total, ending with 1 = previous ending with 0.
 *    5. The recurrence relation simplifies to Fibonacci sequence logic.
 *    6. Iteratively compute values up to n using variables a, b, c.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
public:
    int countStrings(int n) {
        // code here
        int a = 1;
        int b = 1;
        int c = 0;
        for (int i = 1; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

// Key Points
// 1. Problem reduces to Fibonacci recurrence.
// 2. Strings ending with 0 can follow both 0 and 1.
// 3. Strings ending with 1 can only follow 0.
// 4. Base case: for n=1, count = 2 (0 and 1).
// 5. Iterative approach avoids recursion overhead.
// 6. Space optimized to O(1) using variables.
// 7. Efficient for large n due to linear time.