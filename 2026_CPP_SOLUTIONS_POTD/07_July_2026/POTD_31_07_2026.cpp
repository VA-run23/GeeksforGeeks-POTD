// Subsets with Products of Distinct Primes

/*
 *    1. The problem asks to count subsets where the product of elements is composed of distinct prime factors only.
 *    2. Numbers like 4, 9, and 25 are excluded because they introduce repeated prime factors (e.g., 2², 3², 5²).
 *    3. Each valid number is represented as a bitmask of primes dividing it, ensuring subsets remain distinct in prime factorization.
 *    4. Dynamic programming is used with a 1024-sized dp array (since there are 10 primes ≤ 30, 2¹⁰ = 1024 possible masks).
 *    5. For each number, update dp states only if its prime mask does not overlap with the current subset mask.
 *    6. Special handling is done for the number 1, which can be freely included in subsets without affecting prime factorization.
 *    7. Time Complexity: O(n · 2^p) where p=10 (small constant), Space Complexity: O(2^p).
 */

class Solution {
    public:
    int countSubsets(vector<int> &arr) {
        // code here
        int mod = 1e9 + 7;
        vector<int> mp(31);
        vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        for (int i = 2; i <= 30; ++i) {
            if (i%4 == 0 || i%9 == 0 || i == 25)
                continue;
            int mask = 0;
            for (int j = 0; j<10; ++j) {
                if (i%prime[j] == 0)
                    mask |= 1 << j;
            }
            mp[i] = mask;
        }
        
        auto pow2 = [&](int n) {
            long ans = 1, m = 2;
            while (n != 0) {
                if (n&1)
                    ans = (ans*m)%mod;
                m = (m*m)%mod;
                n >>= 1;
            }
            return ans;
        };
        
        int one = 0;
        vector<int> dp(1024), cnt(31);
        dp[0] = 1;
        
        for (int i: arr) {
            if (i == 1)
                one++;
            else if (mp[i] != 0)
                cnt[i]++;
        }
        
        for (int i = 0; i<31; ++i) {
            if (cnt[i] == 0)
                continue;
            for (int j = 0; j<1024; ++j) {
                if (j & mp[i])
                    continue;
                dp[j | mp[i]] = (int)((dp[j | mp[i]] + dp[j] * (long)cnt[i]) % mod);
            }
        }
        
        long ans = 0;
        for (int val: dp)
            ans = (ans + val)%mod;
        ans--;
        
        if (one != 0) ans = ans * pow2(one)
            % mod;
        
        return (int)ans;
    }
};

// Key Points
// 1. Uses bitmask representation for prime factors.
// 2. Excludes numbers with repeated prime factors (like 4, 9, 25).
// 3. Dynamic programming ensures subsets remain valid.
// 4. dp array size is 1024 (2^10 for 10 primes).
// 5. Special handling for number 1 with pow2(one).
// 6. Efficient modulo arithmetic keeps results bounded.
// 7. Final answer counts all valid subsets with distinct prime products.