/*
    1. This function checks if the string `tar` can be formed from `pat` using stack-like operations: append or delete.
    2. It uses two pointers `i` and `j` starting from the end of `pat` and `tar` respectively.
    3. If characters at `pat[i]` and `tar[j]` match, both pointers move left—simulating a successful append.
    4. If they don't match, we simulate a delete by skipping two characters from `pat` (one append + one delete).
    5. The loop continues until either string is fully traversed.
    6. If all characters in `tar` are matched (`j < 0`), return true; otherwise, return false.
    7. Time Complexity: O(n) where n = length of `pat`; Space Complexity: O(1) as no extra space is used.
*/

class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
        int i = pat.size() - 1;
        int j = tar.size() - 1;

        while (i >= 0 && j >= 0) {
            if (pat[i] == tar[j]) {
                i--;
                j--;
            } else {
                i -= 2;
            }
        }

        return j < 0;
    }
};