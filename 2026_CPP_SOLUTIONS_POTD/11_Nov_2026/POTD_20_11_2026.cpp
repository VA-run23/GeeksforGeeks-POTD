// Min Flips to Make Binary String Alternating

/*
 * 1. An alternating binary string can only have two valid patterns:
 *      - "010101..."
 *      - "101010..."
 *
 * 2. Count the number of positions that do not match the first pattern
 *    ("010101...").
 *
 * 3. Let mismatch be the number of such positions.
 *
 * 4. If mismatch positions differ from "010101...",
 *    then exactly (n - mismatch) positions differ from "101010..."
 *    because every matching position in one pattern is a mismatch in the other.
 *
 * 5. Therefore:
 *      - Flips required for "010101..." = mismatch
 *      - Flips required for "101010..." = n - mismatch
 *
 * 6. Return the minimum of the two values since we need the minimum
 *    number of flips to make the string alternating.
 *
 * 7. Time Complexity: O(n)
 *    Space Complexity: O(1)
 */

class Solution {
public:
    int minFlips(string &s) {
        int n = s.size();
        int mismatch = 0;

        for (int i = 0; i < n; i++) {

            // Expected character for pattern "010101..."
            if (s[i] != ('0' + (i % 2))) {
                mismatch++;
            }
        }

        return min(mismatch, n - mismatch);
    }
};

// Key Points
// 1. Only two alternating patterns are possible.
// 2. Count mismatches with pattern "010101...".
// 3. mismatch represents flips needed for "010101...".
// 4. n - mismatch represents flips needed for "101010...".
// 5. Every match in one pattern is a mismatch in the other.
// 6. Return the minimum flips among both patterns.
// 7. Optimal solution with O(n) time and O(1) space.