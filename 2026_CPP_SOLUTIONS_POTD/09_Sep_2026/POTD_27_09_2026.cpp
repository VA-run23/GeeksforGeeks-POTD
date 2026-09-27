// Longest Colored Path

/*
 *    1. Problem: Given a tree with nodes colored (string s), find the longest path
 *       such that adjacent nodes have different colors.
 *    2. Approach:
 *       - Build adjacency list from edges.
 *       - For each connected component of same-colored nodes:
 *         - Find diameter (longest path) using two DFS calls.
 *         - Track farthest distance for each node.
 *       - Then, for each edge connecting different colors:
 *         - Combine farthest distances from both sides.
 *         - Update answer with far[u] + far[v] + 2.
 *    3. Key idea: longest path is either within a same-color component (diameter),
 *       or across two different-colored components joined by an edge.
 *    4. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int longestPath(string& s, vector<vector<int>>& edges) {
        int n = s.length(), ans = 0;
        vector<vector<int>> adj(n);

        // Step 1: Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> far(n, 0);
        vector<bool> vis(n, false);

        // Helper to find farthest node in same-color component
        auto getFar = [&](int start) {
            int maxD = -1, farN = start;
            auto dfs = [&](auto& self, int u, int p, int d) -> void {
                if (d > maxD) { maxD = d; farN = u; }
                for (int v : adj[u]) {
                    if (v != p && s[v] == s[start]) self(self, v, u, d + 1);
                }
            };
            dfs(dfs, start, -1, 0);
            return farN;
        };

        // Step 2: Process each same-color component
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int a = getFar(i);
                int b = getFar(a);

                auto fillDist = [&](auto& self, int u, int p, int d) -> void {
                    vis[u] = true;
                    far[u] = max(far[u], d);
                    ans = max(ans, d + 1);
                    for (int v : adj[u]) {
                        if (v != p && s[v] == s[i]) self(self, v, u, d + 1);
                    }
                };

                fillDist(fillDist, a, -1, 0);
                fillDist(fillDist, b, -1, 0);
            }
        }

        // Step 3: Check edges between different colors
        for (auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1;
            if (s[u] != s[v]) {
                ans = max(ans, far[u] + far[v] + 2);
            }
        }

        return ans;
    }
};

// Key Points
// 1. Same-color components handled via diameter calculation.
// 2. Farthest distances stored for each node.
// 3. Different-color edges combine two components.
// 4. Answer = max of component diameters and cross-color paths.
// 5. Efficient O(n) solution using DFS twice per component.
// 6. Works for large trees due to linear complexity.