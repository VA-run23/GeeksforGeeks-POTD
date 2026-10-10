// Balancing with Distinct Powers

/*
 * 1. Problem:
 *    - Given integers a and b.
 *    - Check if b can be expressed using distinct powers of a with coefficients -1, 0, or 1.
 *
 * 2. Approach:
 *    - Work backwards by repeatedly dividing b by a.
 *
 * 3. At each step:
 *    - Compute remainder r = b % a.
 *
 * 4. Valid remainders:
 *    - r == 0 → just divide b by a.
 *    - r == 1 → subtract 1, then divide.
 *    - r == a-1 → add 1, then divide.
 *
 * 5. Invalid remainder:
 *    - If r is not in {0, 1, a-1}, return false.
 *
 * 6. Continue until b reduces to 0.
 *
 * 7. Final answer:
 *    - If loop completes successfully, return true.
 */

class Solution {
  public:
    bool balancePan(int a, int b) {
        while (b > 0) {
            int r = b % a;
            if (r == 0) {
                b /= a;
            } else if (r == 1) {
                b = (b - 1) / a;
            } else if (r == a - 1) {
                b = (b + 1) / a;
            } else {
                return false;
            }
        }
        return true;
    }
};

// 🔑 Key Points
// - Works by reducing b step by step.
// - Valid remainders: 0, 1, a-1.
// - Each step corresponds to using a distinct power of a.
// - If any remainder is invalid → not possible.
// - Efficient O(log_a b) solution.
// - Space complexity: O(1).
// - Matches GeeksforGeeks "Balancing with Distinct Powers" problem.