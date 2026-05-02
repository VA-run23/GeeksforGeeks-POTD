// Position of the Set Bit

/*
 *    1. The problem requires finding the position of the only set bit in an integer.
 *    2. If the integer has more than one set bit or none, the answer should be -1.
 *    3. We use __builtin_popcount to quickly check the number of set bits.
 *    4. If exactly one set bit exists, we loop to find its position.
 *    5. The loop compares left-shifted values with the given number.
 *    6. Position is returned as 1-based index (least significant bit = position 1).
 *    7. Time Complexity: O(log n), Space Complexity: O(1).
 */

class Solution {
  public:
    int findPosition(int n) {
        // code here
        int x = __builtin_popcount(n);
        if(x != 1)return -1;

        int  y = 0, bit = 1;
        while(y<n){
            if((bit<<y) == n)return y+1;
            y++;
        }
        return -1; // safety fallback
    }
};

// Key Points
// 1. __builtin_popcount efficiently counts set bits.
// 2. If count != 1, return -1 immediately.
// 3. Loop checks powers of two against n.
// 4. Position is returned as 1-based index.
// 5. Always include a final return to avoid undefined behavior.
// 6. Works correctly for inputs like 1, 2, 4, 8, etc.
// 7. Alternative optimal method: use log2(n) + 1 for direct calculation.