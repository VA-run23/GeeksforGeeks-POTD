// Minimum Operations to Reach n

/*
 * 1. Problem:
 *    - Starting from 1, reach n using minimum operations.
 *    - Allowed operations: multiply by 2, add 1.
 *
 * 2. Reverse thinking:
 *    - Instead of building from 1 → n, reduce n → 1.
 *
 * 3. If n is even:
 *    - Best move is divide by 2 (reverse of multiply).
 *
 * 4. If n is odd:
 *    - Best move is subtract 1 (reverse of add).
 *
 * 5. Count operations:
 *    - Each step contributes to operations count.
 *
 * 6. Continue until n = 1:
 *    - Loop reduces n step by step.
 *
 * 7. Final answer:
 *    - Return total operations + 1 (to include starting point).
 */

class Solution {
  public:
    int minOperation(int n) {
        int operations = 0;

        while (n > 1) {
            operations += 1 + (n % 2); // divide if even, subtract if odd
            n /= 2;
        }

        return operations + 1; // include starting point
    }
};

// 🔑 Key Points
// - Reverse approach simplifies logic.
// - Even → divide by 2, Odd → subtract 1.
// - Each step adds to operations count.
// - Final +1 accounts for initial step from 1.
// - Time complexity: O(log n).
// - Space complexity: O(1).
// - Efficient solution for large n.