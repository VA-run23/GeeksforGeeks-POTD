/*
    1. The class `Solution` contains functions for Depth-First Search (DFS) traversal of a graph.
    2. The `dfsUtil` function is a recursive helper function that marks a node as visited and explores its adjacent nodes.
    3. If an adjacent node hasn't been visited, `dfsUtil` calls itself recursively to continue the traversal.
    4. The `dfs` function initializes necessary data structures and starts DFS from each unvisited node.
    5. The `visited` vector ensures that nodes are not processed multiple times, avoiding infinite loops.
    6. The traversal order is stored in the `res` vector, capturing the sequence of visited nodes.
    7. Finally, `dfs` returns the `res` vector containing the DFS traversal result.
*/

class Solution {
    public:
        void dfsUtil(int v, vector<vector<int>>& adj, vector<int>& res, vector<bool>& visited) {
            visited[v] = true;
            res.push_back(v);
            for (int u : adj[v]) {
                if (!visited[u])
                    dfsUtil(u, adj, res, visited);
            }
        }
    
        vector<int> dfs(vector<vector<int>>& adj) {
            // Code here
            int V = adj.size();
            vector<int> res;
            vector<bool> visited(V, false);
            for (int i = 0; i < V; i++) {
                if (!visited[i])
                    dfsUtil(i, adj, res, visited);
            }
            return res;
        }
};
    