/*
1. The function `wordBreak` checks if the string `s` can be segmented into space-separated 
   words from the given `dictionary`.
2. It creates an unordered_set `u` to store all dictionary words for fast lookup.
3. The maximum word length in the dictionary is calculated and stored in `m`.
4. A dynamic programming (DP) array `dp` is initialized, where `dp[i]` represents 
   whether the first `i` characters of `s` can be segmented.
5. For each index `i` in the string `s`, the loop checks substrings of length 1 to `m` 
   starting from `i`, and updates `dp` if a valid word is found in `u`.
6. The outer loop iterates over the string, skipping indices where `dp[i]` is false, 
   as they cannot form valid segments.
7. Finally, `dp[n]` indicates whether the entire string `s` can be segmented into words.
*/

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        unordered_set<string> u(dictionary.begin(), dictionary.end());
        int n = s.size(), m = 0;
        
        for (auto &w : dictionary) 
            m = max(m, (int)w.size());
        
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            for (int j = 1; j <= m && i + j <= n; j++) {
                if (u.count(s.substr(i, j))) 
                    dp[i + j] = true;
            }
        }
        return dp[n];
    }
};