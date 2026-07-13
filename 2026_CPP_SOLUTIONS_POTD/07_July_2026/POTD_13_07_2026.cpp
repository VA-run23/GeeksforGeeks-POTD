// Minimum Operations to Rearrange Array Cycles

/*
 *    1. The array represents a permutation where each element points to another index.
 *    2. The task is to compute the least common multiple (LCM) of cycle lengths formed by this permutation.
 *    3. Use a visited array to detect and traverse cycles in the permutation.
 *    4. For each cycle, compute its length and factorize it into prime powers.
 *    5. Track the maximum exponent of each prime across all cycles.
 *    6. Multiply primes raised to their maximum exponents to form the final LCM.
 *    7. Time Complexity: O(n√n), Space Complexity: O(n).
 */

class Solution {
  public:
    int minOperations(vector<int> &b) {
        // code here
        int n = b.size();
        vector<bool> vis(n, false);
        
        vector<int> maxExp(n + 2, 0);
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int len = 0;
                int curr = i;
                
                while (!vis[curr]) {
                    vis[curr] = true;
                    curr = b[curr] - 1;
                    len++;
                }
                
                int temp = len;
                for (int d = 2; d * d <= temp; d++) {
                    if (temp % d == 0) {
                        int count = 0;
                        while (temp % d == 0) {
                            temp /= d;
                            count++;
                        }
                        maxExp[d] = max(maxExp[d], count);
                    }
                }
                if (temp > 1) {
                    maxExp[temp] = max(maxExp[temp], 1);
                }
            }
        }
        
        long long ans = 1;
        long long MOD = 1000000007;
        
        for (int i = 2; i <= n; i++) {
            if (maxExp[i] > 0) {
                for (int j = 0; j < maxExp[i]; j++) {
                    ans = (ans * i) % MOD;
                }
            }
        }
        
        return ans;
    }
};

// Key Points
// 1. The array forms disjoint cycles when interpreted as a permutation.
// 2. Each cycle length contributes to the LCM of operations needed.
// 3. Prime factorization ensures efficient LCM computation.
// 4. Maximum exponent tracking avoids repeated multiplication.
// 5. Visited array prevents re-traversing cycles.
// 6. Modulo 1e9+7 keeps results within integer limits.
// 7. Efficient cycle decomposition and LCM calculation.