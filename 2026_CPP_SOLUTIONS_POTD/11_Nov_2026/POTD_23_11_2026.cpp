// Character at Position in Infinite String

/*
 *    1. The problem asks to find the character present at a given position
 *       in the recursively generated infinite string.
 *
 *    2. Let the original string be s of length n.
 *       The recursive construction expands the string by adding '$' separators
 *       and mirrored parts.
 *
 *    3. First, determine the smallest generated string length that contains
 *       the required position.
 *
 *    4. Work backwards from the largest generated level:
 *       - If position lies in the left half, continue in the left part.
 *       - If position lies in the separator region, return '$'.
 *       - If position lies in the mirrored part, map it back to the
 *         corresponding position in the left half.
 *
 *    5. Repeat the reduction until the position falls inside the original string.
 *
 *    6. If the mapped position reaches index n, the character is '$'.
 *
 *    7. Time Complexity: O(log pos), Space Complexity: O(1).
 */

class Solution {
  public:
    char posInfinite(string &s, int pos) {
        // code here

        int n = s.size();
        long long size = n;
        int level = 1;

        // Find the level containing the position
        while (size < pos) {
            size += level + size;
            level++;
        }

        level--;
        pos--;

        // Trace position back to original string
        while (pos > n) {

            long long leftSize = (size - level) / 2;

            if (pos < leftSize) {
                size = leftSize;
            }
            else if (pos >= leftSize && pos < leftSize + level) {
                return '$';
            }
            else {
                pos -= (leftSize + level);
                size = leftSize;
                pos = size - 1 - pos;
            }

            level--;
        }

        if (pos == n)
            return '$';

        return s[pos];
    }
};

// Key Points
// 1. Builds string lengths conceptually without generating the string.
// 2. Finds the recursion level containing the target position.
// 3. Uses reverse mapping to trace the position back.
// 4. Separator positions always contain '$'.
// 5. Mirrored positions are mapped to corresponding left-half indices.
// 6. Avoids constructing exponentially large strings.
// 7. Runs in O(log pos) time with O(1) extra space.