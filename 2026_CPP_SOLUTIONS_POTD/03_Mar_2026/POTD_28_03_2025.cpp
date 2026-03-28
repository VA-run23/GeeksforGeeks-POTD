// Articulation Point in Graph

/*
 *    1. An articulation point is a vertex whose removal increases the number of connected components.
 *    2. The algorithm uses DFS traversal to explore the graph.
 *    3. Discovery time and low values are maintained for each vertex.
 *    4. A root node is an articulation point if it has more than one child in DFS tree.
 *    5. A non-root node is an articulation point if any child cannot reach an ancestor of the node.
 *    6. The adjacency list is built from the given edge list.
 *    7. Time Complexity: O(V + E), Space Complexity: O(V + E)
 */

class Solution {
  public:

    void dfs(int u, int parent, vector<int>& disc, vector<int>& low, vector<bool>& vis, vector<bool>& isArt, vector<vector<int>>& adj, int& time) {
        vis[u] = true;
        disc[u] = low[u] = time++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (!vis[v]) {
                children++;
                dfs(v, u, disc, low, vis, isArt, adj, time);

                low[u] = min(low[u], low[v]);

                if (parent != -1 && low[v] >= disc[u]) {
                    isArt[u] = true;
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }

        if (parent == -1 && children > 1) {
            isArt[u] = true;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, -1), low(V, -1);
        vector<bool> vis(V, false), isArt(V, false);
        int time = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, disc, low, vis, isArt, adj, time);
            }
        }

        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isArt[i]) result.push_back(i);
        }

        return result.empty() ? vector<int>{-1} : result;
    }
};

// Key Points
// 1. Articulation points are critical for network reliability.
// 2. DFS traversal helps track discovery and low times.
// 3. Root nodes require special handling in DFS.
// 4. Non-root nodes are checked using low[v] >= disc[u] condition.
// 5. Adjacency list representation ensures efficient traversal.
// 6. The algorithm works for disconnected graphs as well.
// 7. Efficient with linear time complexity relative to graph size