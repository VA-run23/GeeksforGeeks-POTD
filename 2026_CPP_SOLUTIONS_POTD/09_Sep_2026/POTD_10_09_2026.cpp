// Pairs with Given GCD and LCM

/*
 *    1. The problem asks to count pairs (a, b) such that gcd(a, b) = x and lcm(a, b) = y.
 *    2. First check feasibility: if y % x != 0, no such pairs exist.
 *    3. Let n = y / x. Then a = x * p, b = x * q where p * q = n and gcd(p, q) = 1.
 *    4. Iterate over all divisors p of n, compute q = n / p.
 *    5. If gcd(p, q) = 1, then (a, b) and (b, a) are valid pairs.
 *    6. Count both pairs, but if p == q, count only once.
 *    7. Time Complexity: O(√n), Space Complexity: O(1).
 */

class Solution {
  public:
    int pairCount(int x, int y) {
        if (y % x != 0) return 0;

        int n = y / x;
        int ans = 0;

        for (int p = 1; p * p <= n; p++) {
            if (n % p == 0) {
                int q = n / p;

                if (__gcd(p, q) == 1) {
                    ans += 2; 
                    if (p == q) ans--; 
                }
            }
        }
        return ans;
    }
};

// Key Points
// 1. Valid pairs exist only if y % x == 0.
// 2. Reduce problem to finding coprime factor pairs of n = y/x.
// 3. Each divisor pair (p, q) gives (x*p, x*q).
// 4. gcd(p, q) must equal 1 for validity.
// 5. Count both (a, b) and (b, a), adjust if p == q.
// 6. Efficient divisor iteration up to √n.
// 7. Runs in O(√n) time with O(1) space.