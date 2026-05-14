// Search for Subarray

/*
 *    1. This problem requires finding all occurrences of a subarray within another array.
 *    2. The approach used here is the Knuth-Morris-Pratt (KMP) algorithm adapted for arrays.
 *    3. The LPS (Longest Prefix Suffix) array is computed for the pattern subarray.
 *    4. The main array is scanned while maintaining a pointer to the pattern.
 *    5. On mismatch, the LPS array helps skip unnecessary comparisons.
 *    6. On full match, the starting index of the subarray is stored in the result.
 *    7. Time Complexity: O(n + m), Space Complexity: O(m), where n = size of main array, m = size of subarray.
 */

class Solution {
  private:
    void computeLPSArray(vector<int>& pat, vector<int>& lps) {
        
        int m = pat.size();
        for (int i = 1; i < m; i++) {
            int j = lps[i - 1];
            while (j > 0 && pat[i] != pat[j]) {
                j = lps[j - 1];
            }
            if (pat[i] == pat[j]) {
                j++;
            }
            lps[i] = j;
        }
    }
    
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        
        int n = a.size();
        int m = b.size();

        vector<int> lps(m, 0);
        computeLPSArray(b, lps);

        vector<int> ans;

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j > 0 && a[i] != b[j]) {
                j = lps[j - 1];
            }
            if (a[i] == b[j]) {
                j++;
            }
            if (j == m) {
                ans.push_back(i - m + 1);
                j = lps[j - 1];
            }
        }

        return ans;
    }
};

// Key Points
// 1. KMP algorithm is used for efficient subarray search.
// 2. LPS array avoids redundant comparisons.
// 3. Works for integer arrays instead of strings.
// 4. Returns all starting indices of matches.
// 5. Handles overlapping occurrences correctly.
// 6. Linear time complexity ensures scalability.
// 7. Space usage is proportional to the subarray size.