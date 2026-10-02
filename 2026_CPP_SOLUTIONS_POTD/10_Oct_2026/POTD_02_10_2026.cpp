// Lexicographically Smallest Rotation

/*
 * 1. Problem:
 *    - Given a string s, find the lexicographically smallest rotation of s.
 *
 * 2. Approach:
 *    - Use Booth’s algorithm to find the minimal rotation efficiently.
 *
 * 3. Maintain two candidate indices i and j:
 *    - i = current best rotation start.
 *    - j = competing rotation start.
 *
 * 4. Compare characters at positions (i+k) % n and (j+k) % n:
 *    - If equal → increment k.
 *    - If different → discard the worse rotation.
 *
 * 5. Update indices:
 *    - If charI > charJ → move i forward.
 *    - Else → move j forward.
 *    - Ensure i ≠ j, adjust accordingly.
 *
 * 6. Continue until one candidate remains:
 *    - The smaller index gives the starting position of minimal rotation.
 *
 * 7. Construct answer:
 *    - Return s.substr(startPos) + s.substr(0, startPos).
 */

class Solution {
public:
    string lexiString(string &s) {
        int n = s.length();
        int i = 0, j = 1, k = 0;

        while (i < n && j < n && k < n) {
            char charI = s[(i + k) % n];
            char charJ = s[(j + k) % n];

            if (charI == charJ) {
                k++;
            } else {
                if (charI > charJ) {
                    i += k + 1;
                } else {
                    j += k + 1;
                }
                if (i == j) j++;
                k = 0;
            }
        }

        int startPos = min(i, j);
        return s.substr(startPos) + s.substr(0, startPos);
    }
};

// 🔑 Key Points
// - Booth’s algorithm finds minimal rotation in O(n).
// - Maintains two candidate indices and compares cyclic substrings.
// - Discards worse candidate when mismatch occurs.
// - Final answer = rotation starting at min(i, j).
// - Efficient and avoids generating all rotations.
// - Time complexity: O(n).
// - Space complexity: O(1).