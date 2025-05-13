/*
  1. Purpose: This function efficiently computes the binomial coefficient (nCr) using modular arithmetic.
  2. Avoids Factorial Computation: Instead of direct factorial calculations, it uses an iterative approach.
  3. Modular Inverse: Fermat's theorem is applied to handle division under modulo constraints.
  4. Time Complexity: Runs in O(r) time, making it optimal for large values of n and r.
  5. Space Complexity: Uses only O(1) extra space, improving efficiency compared to DP-based solutions.
  6. Constraints Handling: Returns 0 if r > n, ensuring valid combinations.
  7. Modular Arithmetic: Uses modulo 1e9+7 to prevent integer overflow in competitive programming scenarios.
*/

class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        const int MOD = 1000000007;
        long long result = 1;

        for (int i = 0; i < r; i++) {
            result = (result * (n - i)) % MOD;
            result = (result * modInverse(i + 1, MOD)) % MOD;
        }

        return result;
    }

  private:
    long long modInverse(long long x, int mod) {
        long long res = 1, power = mod - 2;
        while (power) {
            if (power % 2) res = (res * x) % mod;
            x = (x * x) % mod;
            power /= 2;
        }
        return res;
    }
};