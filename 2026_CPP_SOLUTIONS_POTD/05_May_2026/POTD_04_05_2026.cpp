// Binary Palindrome Check

/*
 *    1. Identify the binary representation of the given number.
 *    2. Use bitwise operations to extract the most significant bit (MSB).
 *    3. Use bitwise operations to extract the least significant bit (LSB).
 *    4. Compare MSB and LSB for equality.
 *    5. Move inward by decrementing MSB position and incrementing LSB position.
 *    6. Repeat until all pairs of bits are checked or a mismatch is found.
 *    7. Time Complexity: O(log n), Space Complexity: O(1) since no extra storage is used.
 */

class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        if (n == 0) return true;

        int left = 31 - __builtin_clz(n); 
        int right = 0;                   

        while (left > right) {
            int leftBit = (n >> left) & 1;
            int rightBit = (n >> right) & 1;
            if (leftBit != rightBit) return false;
            left--;
            right++;
        }
        return true;
    }
};

// Key Points
// 1. Binary palindrome means the binary string reads the same forward and backward.
// 2. LSB is extracted using bitwise AND with 1.
// 3. MSB is found using __builtin_clz to count leading zeros.
// 4. No need to store the entire binary representation.
// 5. Comparisons are done directly on bit positions.
// 6. Efficient approach with constant space usage.
// 7. Works optimally for integers within 32-bit range.