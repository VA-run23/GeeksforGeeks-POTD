// Sum of Pairwise ANDs

/*
 *    1. The problem asks to compute the sum of bitwise ANDs of all pairs in the array.
 *    2. Key observation: contribution of each bit can be calculated independently.
 *    3. For bit position i (0–31), count how many numbers have that bit set.
 *    4. If cnt numbers have bit i set, then number of pairs = cnt * (cnt - 1) / 2.
 *    5. Each such pair contributes (1 << i) to the sum.
 *    6. Add contributions across all bits to get final answer.
 *    7. Time Complexity: O(32 * n) ≈ O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        long long ans = 0;
        int n = arr.size();

        for (int i = 0; i < 32; i++) {
            long long cnt = 0;
            for (int j = 0; j < n; j++) {
                cnt += (arr[j] >> i) & 1;
            }
            if (cnt > 1) {
                ans += (1LL << i) * (cnt * (cnt - 1)) / 2;
            }
        }
        return ans;
    }
};

// Key Points
// 1. Each bit contributes independently to AND sum.
// 2. Count how many numbers have bit i set.
// 3. Number of valid pairs = cnt choose 2.
// 4. Contribution = (1 << i) * pairs.
// 5. Sum contributions across all 32 bits.
// 6. Efficient O(n) solution with constant extra space.
// 7. Avoids brute force O(n²) pair checking.