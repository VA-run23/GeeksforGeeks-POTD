// Count of Sum of Consecutives

/*
 *    1. The problem asks how many ways n can be expressed as a sum of consecutive natural numbers.
 *    2. A sequence of length i has sum (i*(i-1))/2 added to a multiple of i.
 *    3. Rearranging, n - (i*(i-1))/2 must be divisible by i for a valid sequence.
 *    4. Iterate i from 2 up to √(2n) to check possible sequence lengths.
 *    5. For each valid i, increment the count if divisibility holds.
 *    6. This ensures all possible consecutive sequences are considered.
 *    7. Time Complexity: O(√n), Space Complexity: O(1).
 */

class Solution {
  public:
    int getCount(int n) {
        // code here
        int cnt = 0, sm = 0, i = 0;
        for (i = 2; i*i <= 2*n; i++) {
            int val = n - (i*(i - 1))/2;
            if (val % i == 0) cnt++;
        }
        return cnt;
    }
};

// Key Points
// 1. Expressing n as consecutive sums reduces to divisibility checks.
// 2. Sequence length i determines the required adjustment term (i*(i-1))/2.
// 3. Valid sequences exist only if adjusted n is divisible by i.
// 4. Loop upper bound √(2n) ensures efficiency.
// 5. Each valid i corresponds to one representation of n.
// 6. No extra storage is needed beyond counters.
// 7. Optimized solution with square-root time complexity.