// Count Prefix-Balanced Binary Strings

/*
 *    1. The problem asks to count the number of prefix-balanced binary strings of length n.
 *    2. A prefix-balanced string means every prefix has more 1s than 0s.
 *    3. This is equivalent to counting valid sequences of parentheses → Catalan numbers.
 *    4. Use DP recurrence: v[i] = Σ (v[j] * v[i-1-j]) for j = 0…i-1.
 *    5. Initialize base cases: v[0] = 1, v[1] = 1.
 *    6. Apply modulo 1e9+7 to keep results within bounds.
 *    7. Time Complexity: O(n²), Space Complexity: O(n).
 */

class Solution {
  public:
    int prefixStrings(int n) {
        // code here
        vector<int> v(n + 1, 0);
        v[0] = 1;
        v[1] = 1;
        int m = 1e9 + 7;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; j++) {
                v[i] = (v[i] + (1LL * v[j] * v[i - 1 - j]) % m) % m;
            }
        }
        return v[n];
    }
};

// Key Points
// 1. Prefix-balanced binary strings map to Catalan numbers.
// 2. Uses DP recurrence relation for Catalan sequence.
// 3. Base cases: v[0] = 1, v[1] = 1.
// 4. Iteratively builds solution up to n.
// 5. Applies modulo 1e9+7 for large results.
// 6. Runs in O(n²) time with O(n) space.
// 7. Elegant DP solution for combinatorial counting.