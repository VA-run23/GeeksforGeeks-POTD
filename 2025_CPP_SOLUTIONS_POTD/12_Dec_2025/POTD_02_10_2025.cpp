/*
    1. The function builds an adjacency list 'to' from the given 'jumps', where each character can jump to itself and other allowed characters.
    2. It precomputes prefix sums ('pref') of ASCII values of characters and frequency counts ('cnt') of each character up to every index for fast range queries.
    3. A DP array 'dp' is maintained where 'dp[i]' stores the maximum score achievable starting from index 'i'.
    4. An auxiliary array 'nxt' keeps track of the next occurrence index of each character while iterating backwards.
    5. For each position 'i', the algorithm checks all possible jump targets 'j' from the current character 'cur', and calculates the score contribution using prefix sums and frequency counts.
    6. The best score for position 'i' is updated as the maximum achievable score considering jumps and future DP values.
    7. Finally, the answer is 'dp[0]', representing the maximum score starting from the beginning of the string.

    Time Complexity: O(n * 26) ≈ O(26n) → linear in string length with constant factor.  
    Space Complexity: O(n * 26) due to prefix frequency counts + O(n) for DP → overall O(26n).
*/

class Solution {
public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        // code here
        int n = s.size();
        if (n <= 1) return 0;

        vector<vector<int>> to(26);
        bool adj[26][26] = {0};
        for (int i = 0; i < 26; i++) adj[i][i] = 1;
        for (auto &e : jumps) adj[e[0]-'a'][e[1]-'a'] = 1;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                if (adj[i][j]) to[i].push_back(j);


        vector<int> pref(n);
        vector<array<int,26>> cnt(n);
        pref[0] = s[0];
        cnt[0].fill(0);
        cnt[0][s[0]-'a'] = 1;

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1] + s[i];
            cnt[i] = cnt[i-1];
            cnt[i][s[i]-'a']++;
        }

        vector<int> dp(n+1, 0);
        int nxt[26]; fill(nxt, nxt+26, -1);

        for (int i = n-1; i >= 0; i--) {
            int cur = s[i]-'a', best = 0;
            for (int j : to[cur]) {
                int x = nxt[j];
                if (x == -1) continue;

                int sum = pref[x] - (i ? pref[i-1] : 0);
                int freq = cnt[x][j] - (i ? cnt[i-1][j] : 0);
                best = max(best, sum - freq * int('a'+j) + dp[x]);
            }
            dp[i] = best;
            nxt[cur] = i;
        }
        return dp[0];
    }
};