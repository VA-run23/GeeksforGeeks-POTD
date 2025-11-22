/*
    1. The code defines a graph using adjacency lists ('g') and a visited array ('vis') to track connected components.
    2. The 'dfs' function performs Depth First Search, marking all nodes in the same component with the same identifier 'cnt'.
    3. In 'minConnect', if the number of edges is less than V-1, it immediately returns -1 (since a connected graph needs at least V-1 edges).
    4. The adjacency list is built by iterating over all edges, adding both directions since the graph is undirected.
    5. A counter 'cnt' is used to count the number of connected components by running DFS from each unvisited node.
    6. The result returned is 'cnt - 1', which represents the minimum number of operations (edges) required to connect all components.
    7. Time Complexity: O(V + E) due to DFS traversal of all vertices and edges; Space Complexity: O(V + E) for adjacency list and visited array.
*/

class Solution {
public:
    vector<vector<int>> g;
    vector<int> vis;

    void dfs(int node, int cnt) {
        vis[node] = cnt;

        for (auto& x : g[node]) {
            if (!vis[x]) {
                dfs(x, cnt);
            }
        }
    }
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here

        if (edges.size() < V - 1)
            return -1;

        g.resize(V);
        vis.resize(V, 0);

        for (auto& x : edges) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }

        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, ++cnt);
            }
        }

        return cnt - 1;
    }
};
