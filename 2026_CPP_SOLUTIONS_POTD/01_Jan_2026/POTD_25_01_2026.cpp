/*
    1. This function calculates the number of valid ways to arrange parentheses for a given n.
    2. If n is odd, it immediately returns 0 since valid parentheses require even counts.
    3. It computes the Catalan number C(pairs) where pairs = n/2, representing valid arrangements.
    4. The loop calculates binomial coefficient (2*pairs choose pairs) using multiplicative formula.
    5. The final result divides by (pairs+1) to obtain the Catalan number.
    6. Time Complexity: O(n) due to the loop running pairs times.
    7. Space Complexity: O(1) since only a few variables are used.
*/

class Solution {
  public:
    int findWays(int n) {
        // code here
        if (n % 2 != 0) return 0;

        int pairs = n / 2; 
        long long res = 1;

        for (int i = 0; i < pairs; i++) {
            res *= (2 * pairs - i);
            res /= (i + 1);
        }

        return (int)(res / (pairs + 1));
    }
};

// Key points:
// - The problem is about counting valid parenthesis sequences.
// - Odd n cannot form valid pairs, hence return 0.
// - Uses Catalan number formula: Cn = (1/(n+1)) * (2n choose n).
// - Loop computes binomial coefficient efficiently without factorials.
// - Division by (pairs+1) ensures correct Catalan number.
// - Time complexity is linear in n, space constant.
// - This is a direct mathematical approach rather than brute force generation.
