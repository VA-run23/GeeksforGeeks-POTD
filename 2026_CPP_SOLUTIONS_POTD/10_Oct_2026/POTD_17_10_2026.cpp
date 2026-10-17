// Transform String

/*
 *    1. The problem asks whether string s1 can be transformed into s2 using the allowed movements.
 *    2. Character 'A' can only move to the left, while character 'B' can only move to the right.
 *    3. Character '#' represents an empty position and can be ignored during comparison.
 *    4. Use two pointers i and j to traverse s1 and s2 while skipping all '#' characters.
 *    5. The relative order of non-'#' characters must remain the same in both strings.
 *    6. For every matched character:
 *       - 'A' must satisfy i >= j.
 *       - 'B' must satisfy i <= j.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    bool isItPossible(string &s1, string &s2) {
        // code here

        int n = s1.size();

        if (s2.size() != n)
            return false;

        int i = 0, j = 0;

        while (i < n && j < n) {

            while (i < n && s1[i] == '#')
                i++;

            while (j < n && s2[j] == '#')
                j++;

            if (i == n || j == n)
                return i == n && j == n;

            if (s1[i] != s2[j])
                return false;

            if (s1[i] == 'A' && i < j)
                return false;

            if (s1[i] == 'B' && i > j)
                return false;

            i++;
            j++;
        }

        return true;
    }
};

// Key Points
// 1. Uses two-pointer traversal on both strings.
// 2. Ignores '#' characters while comparing.
// 3. Order of 'A' and 'B' must remain unchanged.
// 4. 'A' can only move left, never right.
// 5. 'B' can only move right, never left.
// 6. Lengths of both strings must be equal.
// 7. Runs in O(n) time with O(1) extra space.