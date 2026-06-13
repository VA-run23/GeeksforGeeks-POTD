// Count Even Length Binary Strings

/*
 *    1. The problem is to compute the number of binary strings of even length with equal sum in both halves.
 *    2. This reduces to computing binomial coefficients efficiently under modulo arithmetic.
 *    3. The numerator is the product of terms (2n - i) for i from 0 to n-1.
 *    4. The denominator is the factorial of n, i.e., product of (i + 1).
 *    5. Modular inverse is used to divide under modulo, applying Fermat’s Little Theorem.
 *    6. Fast exponentiation (binary exponentiation) is implemented to compute modular inverse.
 *    7. Time Complexity: O(n + log(mod)), Space Complexity: O(1).
 */

class Solution {
  public:
    int solve(int a, int b,int mod){
        int ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * 1LL * a) % mod;
            }
            a = (a * 1LL * a) % mod;
            b >>= 1;
        }
        
        return ans;
    }
    int computeValue(int n) {
        // code here
        int mod = 1000000007;
        int num = 1;
        int deno = 1;
        for (int i = 0; i < n; i++) {
            num = (num * 1LL * (2 * n - i)) % mod;
            deno = (deno * 1LL * (i + 1)) % mod;
        }
        
        int deno_modified = solve(deno, mod - 2, mod);
        
        return (num * 1LL * deno_modified) % mod;
    }
};

// Key Points
// 1. Problem boils down to computing binomial coefficient C(2n, n).
// 2. Modular arithmetic ensures results fit within integer limits.
// 3. Fermat’s Little Theorem is used for modular inverse.
// 4. Binary exponentiation makes inverse computation efficient.
// 5. Loop constructs handle numerator and denominator separately.
// 6. Modulo chosen is a large prime (1e9+7).
// 7. Optimized solution avoids factorial precomputation.