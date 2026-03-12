// Minimum K Consecutive Bit Flips

/*
 *    1. We are given a binary array and an integer k.
 *    2. The task is to flip k consecutive bits to make the array all 1s.
 *    3. A flip means changing 0 to 1 and 1 to 0.
 *    4. We track flips using a sliding window and an auxiliary array.
 *    5. If at any position the bit is effectively 0, we flip the next k bits.
 *    6. If flipping is not possible (out of bounds), return -1.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), flips = 0, flipCount = 0;
        vector<int> isFlipped(n, 0);
    
        for (int i = 0; i < n; ++i) {
            if (i >= k) flipCount -= isFlipped[i - k];
            if ((arr[i] + flipCount) % 2 == 0) {
                if (i + k > n) return -1;
                isFlipped[i] = 1;
                flipCount++;
                flips++;
            }
        }
        return flips;
    }
};

// Key Points
// 1. Sliding window technique is used.
// 2. Auxiliary array tracks flip positions.
// 3. Flip count ensures correct parity of bits.
// 4. If a bit is effectively 0, flip k consecutive bits.
// 5. Out-of-bound flips return -1 immediately.
// 6. Efficiently avoids re-flipping already flipped segments.
// 7. Achieves O(n) time with O(n) extra space.
