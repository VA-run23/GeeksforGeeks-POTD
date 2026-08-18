// Secret Cipher

/*
 *    1. The problem asks to compress a string by repeatedly replacing halves if they are equal.
 *    2. Use polynomial rolling hash to compare substrings efficiently.
 *    3. Precompute powers of base p and their modular inverses for O(1) substring hash queries.
 *    4. Build prefix hash array for the string.
 *    5. Starting from the end, check if the first half equals the second half using hash comparison.
 *    6. If equal, replace with '*' and continue with the half; otherwise keep the character.
 *    7. Time Complexity: O(n log n), Space Complexity: O(n).
 */

class Solution {
  public:
    #define ll long long
    #define MOD 1000000007
    
    ll binpow(ll a, ll b) {
        ll ans = 1;
        while (b > 0) {
            if (b & 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return ans;
    }
    
    string compress(string s) {
        ll p = 31;
        ll n = s.length();
        vector<ll> hash(n + 1), ppow(n + 1, 1), inv(n + 1, 1);
        
        for (ll i = 1; i <= n; i++) {
            ppow[i] = (ppow[i - 1] * p) % MOD;
            inv[i] = binpow(ppow[i], MOD - 2);
        }
        
        for (ll i = 0; i < n; i++) {
            hash[i + 1] = (s[i] - 'a' + 1) * ppow[i];
            hash[i + 1] %= MOD;
            hash[i + 1] = (hash[i] + hash[i + 1]) % MOD;
        }
        
        string ans = "";
        ll i = n;
        while (i >= 1) {
            if (i & 1) {
                ans.push_back(s[--i]);
                continue;
            }
            ll m = i / 2;
            ll val1 = hash[m];
            ll val2 = (hash[i] - hash[m] + MOD) % MOD;
            val2 = (val2 * inv[m]) % MOD;
            if (val1 == val2) {
                ans.push_back('*');
                i = m;
            } else {
                ans.push_back(s[--i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Key Points
// 1. Uses polynomial rolling hash for substring comparison.
// 2. Precomputes powers and modular inverses for efficiency.
// 3. Builds prefix hash array for O(1) substring queries.
// 4. Checks halves for equality using hash values.
// 5. Replaces equal halves with '*' symbol.
// 6. Continues compression until string is reduced.
// 7. Runs in O(n log n) time with O(n) space.