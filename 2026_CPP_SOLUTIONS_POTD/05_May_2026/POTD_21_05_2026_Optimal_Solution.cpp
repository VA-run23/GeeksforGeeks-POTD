// Check if All Bits Set (Optimal Solution)

/*
 *    1. The problem is to check if all bits in a number are set.
 *    2. A number with all bits set is always of the form 2^k - 1.
 *    3. Examples: 1 (0001), 3 (0011), 7 (0111), 15 (1111).
 *    4. Adding 1 to such a number gives a power of 2.
 *    5. The bitwise AND of n and (n+1) will be 0 if all bits are set.
 *    6. This avoids iteration and directly checks the property.
 *    7. Time Complexity: O(1), Space Complexity: O(1).
 */

class Solution {
  public:
    bool isBitSet(int n) {
        // code here
        return n > 0 && ((n & (n + 1)) == 0);
    }
};

// Key Points
// 1. Uses mathematical property of numbers with all bits set.
// 2. Avoids looping through bits.
// 3. Checks if n is of form 2^k - 1.
// 4. Efficient bitwise AND operation used.
// 5. Handles edge case when n = 0.
// 6. Constant time and space solution.
// 7. More optimal than iterative approach.