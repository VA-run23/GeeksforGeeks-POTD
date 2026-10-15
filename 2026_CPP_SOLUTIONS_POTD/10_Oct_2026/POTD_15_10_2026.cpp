// Maximum Value without Three Consecutive Set Bits

/*
 *    1. The problem asks to find the maximum value ≤ n that does not contain three consecutive set bits.
 *    2. Traverse bits from the most significant bit towards the least significant bit.
 *    3. For each position i, check whether bits i, i-1, and i-2 are all set.
 *    4. If three consecutive set bits are found, unset the lowest bit among them.
 *    5. This reduces the number while keeping it as large as possible.
 *    6. Continue checking higher bit groups until all triples of consecutive set bits are removed.
 *    7. Time Complexity: O(1) (maximum 31 bit checks), Space Complexity: O(1).
 */

class Solution {
  public:
    int maxValue(int n) {
        // code here
        for (int i = 30; i >= 2; i--) {
            int mask1 = 1 << i;
            int mask2 = 1 << (i - 1);
            int mask3 = 1 << (i - 2);

            if ((mask1 & n) && (mask2 & n) && (mask3 & n)) {
                n = (n ^ mask3);
            }
        }

        return n;
    }
};

// Key Points
// 1. Works directly on the binary representation of n.
// 2. Detects patterns of three consecutive set bits.
// 3. Unsets the lowest bit of the detected triplet.
// 4. Keeps the resulting number as large as possible.
// 5. Processes bits from MSB to LSB.
// 6. Uses bit masks for efficient checking.
// 7. Runs in constant time and constant space.