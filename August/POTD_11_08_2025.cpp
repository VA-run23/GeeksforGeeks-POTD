/*
    1. This code finds the maximum sum of lengths of two non-overlapping odd-length palindromic substrings in a given string.
    2. It uses Manacher’s algorithm to compute the radius of the longest odd-length palindrome centered at each index.
    3. Two arrays, maxEnd and maxStart, track the best palindrome ending before or starting after each index.
    4. These arrays are built by scanning left-to-right and right-to-left, updating with the longest palindrome found so far.
    5. The final result is computed by trying every split point and summing the best palindrome on the left and right sides.
    6. Time Complexity: O(n), where n is the length of the string — due to linear scans and Manacher’s algorithm.
    7. Space Complexity: O(n) — for storing palindrome radii and prefix/suffix maximum arrays.
*/

class Solution {
  public:
    int maxSum(string &s) {
        // code here
        int n = s.size();
        vector<int> d = manacherOdd(s);

        vector<int> maxEnd(n, 0), maxStart(n, 0);

        for (int i = 0; i < n; ++i) {
            int r = i + d[i] - 1;
            if (r < n) {
                maxEnd[r] = max(maxEnd[r], 2 * d[i] - 1);
            }
        }
        for (int i = 1; i < n; ++i) {
            maxEnd[i] = max(maxEnd[i], maxEnd[i - 1]);
        }

        for (int i = n - 1; i >= 0; --i) {
            int l = i - d[i] + 1;
            if (l >= 0) {
                maxStart[l] = max(maxStart[l], 2 * d[i] - 1);
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            maxStart[i] = max(maxStart[i], maxStart[i + 1]);
        }
        
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, maxEnd[i] + maxStart[i + 1]);
        }

        return ans;
    }

private:
    vector<int> manacherOdd(const string &s) {
        int n = s.size();
        vector<int> d(n);
        int l = 0, r = -1;
        for (int i = 0; i < n; ++i) {
            int k = 1;
            if (i <= r) {
                k = min(d[l + r - i], r - i + 1);
            }
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) {
                ++k;
            }
            d[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }
        return d;
    }
};
