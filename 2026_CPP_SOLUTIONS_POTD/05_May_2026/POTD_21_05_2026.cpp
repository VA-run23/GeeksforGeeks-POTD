// Check if All Bits Set

/*
 *    1. The problem asks to check if all bits in a given integer are set.
 *    2. A bit is considered set if it is equal to 1.
 *    3. The function returns true if all set bits are consecutive starting from LSB.
 *    4. It uses __builtin_popcount to count the number of set bits in the integer.
 *    5. Then iterates through those bits to verify each one is set.
 *    6. If any bit in the range is not set, it returns false.
 *    7. Time Complexity: O(k), where k is the number of set bits; Space Complexity: O(1).
 */

class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        int x = 1;
        if(n  == 0) return false;
        int k = __builtin_popcount(n);
        for(int i = 0; i<k; i++){
            if(!(n & x))return false;
            x = x << 1; 
        }

        
        return true;
    }
};

// Key Points
// 1. Uses __builtin_popcount to count set bits.
// 2. Iterates through bits starting from least significant bit.
// 3. Checks consecutiveness of set bits.
// 4. Returns false if any unset bit is found in the range.
// 5. Handles edge case when n = 0.
// 6. Efficient bitwise operations used.
// 7. Constant space solution with linear time in number of set bits.