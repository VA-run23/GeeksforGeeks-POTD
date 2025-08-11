/*
    1. The function 'countPS' counts all palindromic substrings of length ≥ 2 in the input string 's'.
    2. It initializes a 2D boolean DP table 'dp[i][j]' to track whether the substring from index i to j is a palindrome.
    3. It first checks all substrings of length 2 and marks them as palindromes if both characters match.
    4. Then, it iterates over all possible substring lengths ≥ 3 and uses dynamic programming to check if the substring is a palindrome.
    5. A substring 's[i..j]' is a palindrome if 's[i] == s[j]' and the inner substring 's[i+1..j-1]' is also a palindrome.
    6. Each time a valid palindrome is found, the count is incremented.
    7. Time Complexity: O(n²), Space Complexity: O(n²), where n is the length of the string.
*/

class Solution {
public:
    int countPS(string &s) {
        // code here
        int n = s.size();
        if (n < 2) return 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                count++;
            }
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len == 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }
};