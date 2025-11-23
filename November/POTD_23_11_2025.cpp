/*
    1. Build adjacency lists: group stones by row and column, connecting stones that share the same row or column.
    2. For each row group with >1 stone, connect the first stone to all others (same for column groups).
    3. This creates a graph where stones are nodes and edges represent row/column sharing.
    4. Use a DFS traversal to explore each connected component of stones.
    5. Count how many stones are in each component; you can remove all but one (component_size - 1).
    6. Accumulate these removable counts across all components to get the final answer.
    7. Time Complexity: O(n^2) in worst case (building adjacency + DFS), Space Complexity: O(n^2) for adjacency + O(n) for visited array.
*/

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        int ans = 0;
        int n = stones.size();
        vector<vector<int>> adj(n);
        unordered_map<int, vector<int>> row, col;
        for (int i = 0; i < n; i++) {
            row[stones[i][0]].push_back(i);
            col[stones[i][1]].push_back(i);
        }

        for (auto [x, y] : row) {
            if (y.size() > 1) {
                for (int i = 1; i < y.size(); i++) {
                    adj[y[0]].push_back(y[i]);
                    adj[y[i]].push_back(y[0]);
                }
            }
        }
        for (auto [x, y] : col) {
            if (y.size() > 1) {
                for (int i = 1; i < y.size(); i++) {
                    adj[y[0]].push_back(y[i]);
                    adj[y[i]].push_back(y[0]);
                }
            }
        }
        vector<bool> vis(n, false);
        int cnt = 0;
        auto dfs = [&](auto&& dfs, int node) -> void {
            cnt++;
            vis[node] = true;
            for (auto& x : adj[node]) {
                if (!vis[x]) {
                    dfs(dfs, x);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int old = cnt;
                dfs(dfs, i);
                ans += cnt - old - 1;
            }
        }

        return ans;
    }
};