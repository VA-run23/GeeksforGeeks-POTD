/*
    1. The function 'minWindow' finds the minimum window substring in s1 that contains s2 as a subsequence.
    2. It iterates through s1, checking positions where the first character of s2 matches.
    3. From each such position, it moves forward (two-pointer approach) to see if s2 can be matched as a subsequence.
    4. If a full subsequence match is found, it backtracks to shrink the window from the end to find the smallest valid start.
    5. The substring between the found start and end is compared with the current minimum length window.
    6. If smaller, it updates the result substring and minimum length.
    7. Time Complexity: O(m * n) in worst case (m = length of s1, n = length of s2); Space Complexity: O(1) since only variables are used.
*/

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int m = s1.size(), n = s2.size();
        string res = "";
        int minLen = INT_MAX;

        for (int i = 0; i < m; ++i) {
            if (s1[i] == s2[0]) {
                int j = i;
                int k = 0;

                while (j < m && k < n) {
                    if (s1[j] == s2[k]) k++;
                    j++;
                }

                if (k == n) {

                    int end = j - 1;
                    k = n - 1;
                    while (j >= i) {
                        j--;
                        if (s1[j] == s2[k]) k--;
                        if (k < 0) break;
                    }
                    int start = j;
                    if (end - start + 1 < minLen) {
                        minLen = end - start + 1;
                        res = s1.substr(start, minLen);
                    }
                }
            }
        }

        return res;
    }
};