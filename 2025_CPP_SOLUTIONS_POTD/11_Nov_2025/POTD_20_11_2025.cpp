/*
    1. The code defines a function `minCost` that calculates the minimum cost to transform string `s` into string `t` using given character transformations with associated costs.
    2. It initializes a 26x26 matrix `dist` with INF (1e9), representing the minimum cost to convert one character to another; diagonal entries are set to 0 since a character can transform to itself at zero cost.
    3. For each transformation rule `(u -> v)` with cost, it updates `dist[u][v]` to the minimum cost among possible transformations.
    4. It applies the Floyd–Warshall algorithm to compute the shortest transformation cost between all pairs of characters, ensuring indirect transformations are considered.
    5. For each position in strings `s` and `t`, if characters differ, it tries to find a common character `c` such that both `s[i]` and `t[i]` can be transformed into `c` with minimal combined cost.
    6. If no valid transformation exists for any differing character pair, the function returns -1; otherwise, it accumulates the minimal costs into `ans`.
    7. Finally, the function returns the total minimum cost `ans` as an integer.

    Time Complexity: O(26^3 + 26 * |s|) ≈ O(|s| + 17,576) → dominated by Floyd–Warshall (constant since alphabet size is fixed).
    Space Complexity: O(26^2) = O(1) (constant space for the distance matrix).
*/

/* 🔑 Key Points:
- Uses Floyd–Warshall to precompute all-pairs shortest transformation costs.
- Checks each character pair in `s` and `t` for possible transformation via an intermediate character.
- Returns -1 if any pair cannot be transformed.
- Efficient since alphabet size (26) is fixed, making preprocessing constant-time relative to input size.
*/

class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));
        for (int i = 0; i < 26; i++) dist[i][i] = 0;
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            if (a == b) continue;
            int best = INF;
            for (int c = 0; c < 26; c++) {
                if (dist[a][c] < INF && dist[b][c] < INF) {
                    best = min(best, dist[a][c] + dist[b][c]);
                }
            }
            if (best == INF) return -1;
            ans += best;
        }
        return ans;
    }
};