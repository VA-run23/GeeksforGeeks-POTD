// Minimum Steps to Reach Zero

/*
 *    1. The problem asks to find the minimum number of operations required to reduce n to 0.
 *    2. Allowed operations:
 *       - If n is divisible by 3, divide it by 3.
 *       - Otherwise, subtract 1 from n.
 *    3. Use a greedy approach to always perform division when possible.
 *    4. Division reduces the number much faster than repeated subtraction.
 *    5. Count each operation performed until n becomes 0.
 *    6. The final subtraction of 1 from 1 to 0 is accounted for by returning ans - 1.
 *    7. Time Complexity: O(log₃n + number of subtractions), Space Complexity: O(1).
 */

class Solution {
  public:
    int minimumStep(int n) {
        // code here
        int ans = 0;

        while (n != 0) {
            if (n % 3 == 0) {
                ans++;
                n = n / 3;
            }
            else {
                ans++;
                n = n - 1;
            }
        }

        return ans - 1;
    }
};

// Key Points
// 1. Greedily divides by 3 whenever possible.
// 2. Otherwise performs a subtraction operation.
// 3. Division significantly reduces the remaining work.
// 4. Each operation contributes 1 to the answer.
// 5. Loop continues until n becomes 0.
// 6. Uses constant extra space.
// 7. Efficient solution with near-logarithmic behavior.