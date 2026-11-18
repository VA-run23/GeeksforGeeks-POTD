// XOR of Numbers in Range [L, R]

/*
 *    1. The problem asks to find the XOR of all numbers in the range [L, R].
 *
 *    2. Observe that:
 *       XOR(L...R) = XOR(0...R) ^ XOR(0...(L-1))
 *
 *    3. For each bit position b, count how many numbers in the prefix
 *       have that bit set.
 *
 *    4. For a bit b:
 *       - Pattern repeats every 2^(b+1) numbers.
 *       - Each complete cycle contributes 2^b set bits.
 *
 *    5. Add the contribution from the incomplete cycle:
 *       extra = max(0, remainder - 2^b + 1).
 *
 *    6. If the total count of set bits at position b is odd,
 *       then that bit contributes to the prefix XOR.
 *
 *    7. Compute prefix XORs for R and (L-1), then XOR them to obtain
 *       the answer for the range.
 *       Time Complexity: O(31), Space Complexity: O(1).
 */

class Solution {
  public:
    int findXOR(int l, int r) {
        // XOR from 0 to L-1
        int ans1 = 0;

        for (int b = 0; b < 31 && (1LL << b) <= l - 1; b++) {

            long long cycle = (1LL << (b + 1));

            long long fullCycles = (l - 1) / cycle;
            long long remainder = (l - 1) % cycle;

            long long extra =
                max(0LL, remainder - (1LL << b) + 1);

            long long count =
                fullCycles * (1LL << b) + extra;

            if (count & 1)
                ans1 |= (1LL << b);
        }

        // XOR from 0 to R
        int ans2 = 0;

        for (int b = 0; b < 31 && (1LL << b) <= r; b++) {

            long long cycle = (1LL << (b + 1));

            long long fullCycles = r / cycle;
            long long remainder = r % cycle;

            long long extra =
                max(0LL, remainder - (1LL << b) + 1);

            long long count =
                fullCycles * (1LL << b) + extra;

            if (count & 1)
                ans2 |= (1LL << b);
        }

        return ans1 ^ ans2;
    }
};

// Key Points
// 1. Uses XOR(L...R) = XOR(0...R) ^ XOR(0...(L-1)).
// 2. Computes prefix XOR bit by bit.
// 3. Set-bit pattern repeats in fixed cycles.
// 4. Complete cycles contribute predictable counts.
// 5. Partial cycle contribution is handled separately.
// 6. A bit appears in XOR only when its count is odd.
// 7. Runs in constant O(31) time with O(1) space.