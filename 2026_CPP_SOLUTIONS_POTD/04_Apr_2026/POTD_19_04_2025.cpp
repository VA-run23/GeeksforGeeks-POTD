// Check if a Number is Power of Another

/*
 *    1. The problem asks whether y can be expressed as x^k for some integer k ≥ 1.
 *    2. Special cases: if x = 1 and y ≠ 1, return false since 1^k is always 1.
 *    3. If y = 1, return true because any number raised to power 0 gives 1.
 *    4. Iteratively divide y by x while y > x to check divisibility.
 *    5. If at any step y % x ≠ 0, return false since y is not a pure power of x.
 *    6. Continue until y reduces to x, confirming y is indeed a power of x.
 *    7. Time Complexity: O(log_y) due to repeated division; Space Complexity: O(1).
 */

class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
        if (x == 1 && y != 1) return false; 
        if (y == 1) return true;        

        while (y > x) {
            if (y % x != 0) return false;   
            y /= x;
        }
        return y == x;
    }
};

// Key Points
// 1. Handles edge cases for x = 1 and y = 1.
// 2. Uses iterative division to check power relation.
// 3. Avoids floating-point operations for precision.
// 4. Efficient with logarithmic time complexity.
// 5. Constant space usage.
// 6. Works for positive integers only.
// 7. Simple and clean implementation.