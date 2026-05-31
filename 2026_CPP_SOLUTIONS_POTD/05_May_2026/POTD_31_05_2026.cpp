// Express as Consecutive Number Sum

/*
 *    1. A number can be expressed as the sum of consecutive integers if it has an odd divisor greater than 1.
 *    2. Powers of two lack odd divisors other than 1, so they cannot be expressed this way.
 *    3. The bitwise trick (n & (n - 1)) checks if n is a power of two.
 *    4. If (n & (n - 1)) == 0, then n is a power of two.
 *    5. If (n & (n - 1)) != 0, then n is not a power of two and can be expressed as consecutive sum.
 *    6. This provides a constant-time check without iteration or brute force.
 *    7. Time Complexity: O(1), Space Complexity: O(1)
 */

class Solution {
  public:
    bool isSumOfConsecutive(int n) {
        // code here
        return (n & (n - 1)) != 0;
    }
};

// Key Points
// 1. Only powers of two cannot be expressed as sum of consecutive integers.
// 2. The bitwise trick (n & (n - 1)) efficiently detects powers of two.
// 3. Non-powers of two always have an odd divisor greater than 1.
// 4. Example: 9 = 4 + 5, 15 = 7 + 8, but 8 cannot be expressed.
// 5. This avoids brute force checking of all possible sequences.
// 6. Works for all positive integers greater than 1.
// 7. Optimal solution with O(1) time and space complexity.