// Sum of Numeric Subsequences

/*
 *    1. The problem asks to find the sum of all subsequences formed from a numeric string.
 *
 *    2. Observe that each digit contributes independently to the final answer.
 *       - Every digit appears in exactly 2^(n-1) subsequences.
 *
 *    3. Compute the sum of all digits present in the string.
 *       - sum = Σ (s[i] - '0')
 *
 *    4. Calculate 2^(n-1) using fast modular exponentiation.
 *       - This gives the number of subsequences containing any fixed digit.
 *
 *    5. Since every digit contributes equally many times,
 *       total contribution = digitSum × 2^(n-1).
 *
 *    6. Apply modulo 1e9+7 at every step to avoid overflow.
 *
 *    7. Time Complexity: O(n + log n), Space Complexity: O(1).
 */

class Solution {
  public:
    const int MOD = 1e9 + 7;

    int subsequenceSum(string &s) {
        // code here

        long long sum = 0;

        for (char c : s) {
            sum += (c - '0');
        }

        long long power = 1;
        long long base = 2;
        int exp = s.size() - 1;

        while (exp > 0) {
            if (exp & 1)
                power = (power * base) % MOD;

            base = (base * base) % MOD;
            exp >>= 1;
        }

        return (sum % MOD * power) % MOD;
    }
};

// Key Points
// 1. Every digit appears in exactly 2^(n-1) subsequences.
// 2. Total answer depends only on the sum of digits.
// 3. Uses fast exponentiation to compute powers efficiently.
// 4. Applies modulo 1e9+7 throughout the computation.
// 5. Avoids generating subsequences explicitly.
// 6. Uses constant extra space.
// 7. Runs in O(n + log n) time.