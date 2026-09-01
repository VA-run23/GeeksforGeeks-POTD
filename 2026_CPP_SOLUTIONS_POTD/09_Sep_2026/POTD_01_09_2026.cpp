// Count Palindromic Strings with Constraints

/*
 *    1. The problem asks to count palindromic strings of length ≤ n using k distinct characters.
 *    2. Palindrome construction depends on pairs of characters mirrored around the center.
 *    3. For odd length palindromes → need (len/2) pairs + middle character.
 *    4. For even length palindromes → extend pairs without middle character.
 *    5. Maintain a running product (ways) to track permutations of pairs.
 *    6. Add contributions for each length to total answer modulo 1e9+7.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007LL;
        long long ways = 1; 
        long long ans = 0;

        for (int len = 1; len <= n; ++len) {
            if (len % 2 == 1) {
                int pairs = len / 2;
                ans = (ans + ways * (k - pairs)) % MOD;
            } else {
                int pairs = len / 2;
                ways = (ways * (k - pairs + 1)) % MOD;
                ans = (ans + ways) % MOD;
            }
        }
        return (int)ans;
    }
};

// Key Points
// 1. Palindromes built from mirrored pairs.
// 2. Odd length → add middle character choice.
// 3. Even length → extend pairs only.
// 4. ways tracks multiplicative choices across lengths.
// 5. ans accumulates contributions for each length.
// 6. Uses modulo 1e9+7 for large results.
// 7. Runs in O(n) time with O(1) space.