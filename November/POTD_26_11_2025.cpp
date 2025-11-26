/*
    1. This function computes the bitwise AND of all numbers in the range [l, r] efficiently.
    2. It uses the fact that only the common prefix of l and r remains after ANDing the full range.
    3. The loop shifts both l and r right until they become equal, removing differing bits.
    4. Each shift strips off the least significant bits that would become zero in the final result.
    5. The number of shifts is stored in 'shift' to later restore the common prefix to its original position.
    6. Once l == r, we left-shift l by 'shift' to reconstruct the final ANDed value.
    7. This avoids looping through every number and gives a fast result even for large ranges.

    Time Complexity: O(log(r - l)) — because we shift until l == r.
    Space Complexity: O(1) — no extra space used beyond a few variables.
*/

class Solution {
  public:
    int andInRange(int l, int r) {
        // code here
        int shift = 0;
        while (l < r) {
            l >>= 1;
            r >>= 1;
            shift++;
        }
        return l << shift;
    }
};
