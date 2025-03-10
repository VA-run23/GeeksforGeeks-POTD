/*
1. The function computes the minimum edit distance between two strings `s1` and `s2` using dynamic programming.
2. It initializes two vectors `pre` and `curr` to represent the previous and current rows of the DP table, respectively.
3. The `pre` vector is filled with values 0 to `n` using `std::iota`, indicating the cost to convert an empty string to substrings of `s2`.
4. For each character of `s1` (outer loop), the algorithm calculates edit distances row by row.
5. Each `curr[j]` is determined by checking if characters match or by taking the minimum of insert, delete, or replace operations.
6. After processing each row, `swap(pre, curr)` updates `pre` with the current row for the next iteration.
7. The final edit distance is stored in `pre[n]`, which represents the cost to convert `s1` into `s2`.
*/
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int m = s1.size(), n = s2.size();
        vector<int> pre(n + 1), curr(n + 1);
        iota(pre.begin(), pre.end(), 0);
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++)
                curr[j] = s1[i-1] == s2[j-1] ? pre[j-1] : 1 + min({pre[j-1], pre[j], curr[j-1]});
            swap(pre, curr);
        }
        return pre[n];
    }
};