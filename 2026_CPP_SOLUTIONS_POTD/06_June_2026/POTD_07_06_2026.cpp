// Finding Profession

/*
 *    1. The problem involves determining the profession at a given level and position.
 *    2. The professions alternate between "Engineer" and "Doctor" based on binary representation.
 *    3. Each level doubles the number of positions, forming a binary tree-like structure.
 *    4. The profession is decided by the parity of set bits in (pos-1).
 *    5. If the count of set bits is odd, the profession is "Doctor".
 *    6. If the count of set bits is even, the profession is "Engineer".
 *    7. Time Complexity: O(1), Space Complexity: O(1).
 */

class Solution {
  public:
    string profession(int level, int pos) {
        // code here
        if(__builtin_popcount(pos-1)&1) return "Doctor";
        return "Engineer";
    }
};

// Key Points
// 1. Uses binary representation of position.
// 2. Relies on __builtin_popcount for efficiency.
// 3. Odd set bits → Doctor.
// 4. Even set bits → Engineer.
// 5. Constant time solution.
// 6. Constant space usage.
// 7. Elegant use of bit manipulation.