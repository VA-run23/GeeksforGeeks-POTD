/*
1. The function `countPS` calculates the number of palindromic substrings in a given string `s` using dynamic programming.
2. It initializes a 2D vector `dp` where `dp[i][j]` is true if the substring `s[i:j]` is a palindrome.
3. Pairs of adjacent equal characters (`s[i] == s[i+1]`) are identified and marked as palindromes, incrementing the count.
4. For substrings of length 3 or more, it checks if the first and last characters match (`s[i] == s[j]`) and the inner substring (`dp[i+1][j-1]`) is a palindrome.
5. If the conditions are met, the substring is marked as a palindrome in `dp` and the count is incremented.
6. The outer loop iterates over increasing substring lengths, while the inner loop checks all possible starting positions in `s`.
7. Finally, the function returns the total count of palindromic substrings found in the string `s`.
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