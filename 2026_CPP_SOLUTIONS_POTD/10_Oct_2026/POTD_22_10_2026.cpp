// Minimum Sum Palindrome

/*
 *    1. The problem asks to replace '?' characters so that the string becomes a palindrome with minimum adjacent difference sum.
 *    2. Use two pointers from both ends and process symmetric characters together.
 *    3. If both characters are known and different, forming a palindrome is impossible, so return -1.
 *    4. If one character is '?', replace it with its symmetric counterpart.
 *    5. If both characters are '?', assign a common character (tracked using ch) to minimize future differences.
 *    6. After constructing the palindrome, compute the sum of absolute differences between adjacent characters.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int minimumSum(string &s) {
        // code here
        int n = s.length();

        int first = 0, last = n - 1;
        char ch = 'a';

        while (first <= last) {
            if (s[first] != '?') {
                ch = s[first];
                break;
            }
            if (s[last] != '?') {
                ch = s[last];
                break;
            }
            first++;
            last--;
        }

        first = 0;
        last = n - 1;

        while (first <= last) {
            if (s[first] != '?' && s[last] != '?' &&
                s[first] != s[last]) {
                return -1;
            }
            else if (s[first] == '?' && s[last] != '?') {
                s[first] = s[last];
                ch = s[first];
            }
            else if (s[first] != '?' && s[last] == '?') {
                s[last] = s[first];
                ch = s[first];
            }
            else if (s[first] == '?' && s[last] == '?') {
                s[first] = ch;
                s[last] = ch;
            }
            else {
                ch = s[first];
            }

            first++;
            last--;
        }

        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += abs(s[i] - s[i - 1]);
        }

        return sum;
    }
};

// Key Points
// 1. Uses two-pointer palindrome construction.
// 2. Symmetric characters must match for a valid palindrome.
// 3. Single '?' is replaced with its mirrored character.
// 4. Double '?' pairs are filled with the same character.
// 5. Returns -1 if palindrome formation is impossible.
// 6. Computes adjacent character difference after construction.
// 7. Runs in linear time with constant extra space.