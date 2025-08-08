/*
    1. This function computes the length of the longest prefix of a string 's' that is also a suffix, excluding the full string itself.
    2. It uses the LPS (Longest Prefix Suffix) array from the KMP algorithm, which stores the length of the longest prefix-suffix for each substring ending at index 'i'.
    3. The loop builds the LPS array by comparing characters at current index 'i' and the length pointer 'len', updating the array accordingly.
    4. If characters match, 'len' is incremented and stored in 'lps[i]'; if not, 'len' is reset using previously computed LPS values.
    5. After the loop, 'lps[n-1]' holds the length of the longest prefix which is also a suffix for the entire string.
    6. To satisfy the problem constraint (prefix ≠ entire string), we return 'lps[n-1] - 1' if it's equal to the string length.
    7. Time Complexity: O(n), Space Complexity: O(n) — where 'n' is the length of the string.
*/

class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0, i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return (lps[n - 1] == n) ? lps[n - 1] - 1 : lps[n - 1];
    }
};