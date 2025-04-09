/*
    1. This code finds articulation points in an undirected graph using DFS and Tarjan’s Algorithm.
    2. The dfs function performs a Depth-First Search, tracking discovery and lowest reachable times.
    3. If removing a node increases the number of connected components, it is marked as an articulation point.
    4. The adjacency list adj is built from given edges to represent the graph.
    5. Arrays disc, low, and vis track discovery times, low values, and visited status, respectively.
    6. The isArt array stores articulation points, which are collected in result after DFS traversal.
    7. If no articulation point exists, the function returns {-1}; otherwise, it returns all identified points.
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