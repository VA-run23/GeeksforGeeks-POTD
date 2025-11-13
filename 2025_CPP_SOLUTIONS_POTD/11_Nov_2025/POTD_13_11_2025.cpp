/*
    1. The function checks if s3 can be formed by interleaving s1 and s2 while preserving order.
    2. It uses recursion with memoization: dp[i][j] stores whether s1[i:] and s2[j:] can form s3[i+j:].
    3. Base case: if all characters of s1 and s2 are consumed and length matches s3, return true.
    4. At each step, try to match s3[i+j] with s1[i] or s2[j]; recurse accordingly.
    5. Memoization avoids recomputation, ensuring each (i,j) state is solved once.
    6. Time Complexity: O(n1 * n2) since there are n1*n2 states, each computed once.
    7. Space Complexity: O(n1 * n2) for the dp table plus recursion stack.
*/

class Solution {
public:
    bool isInterleave(string& s1, string& s2, string& s3) {
        // code here
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        auto f = [&](auto&& f, int i, int j) -> int {
            if (i == n1 && j == n2 && i + j == n3)
                return 1;

            if (dp[i][j] != -1)
                return dp[i][j];
            int x = 0, y = 0;
            if (i < n1 && s1[i] == s3[i + j]) {
                x = f(f, i + 1, j);
            }

            if (j < n2 && s2[j] == s3[i + j]) {
                y = f(f, i, j + 1);
            }

            return dp[i][j] = x || y;
        };
        return f(f, 0, 0);
    }
};