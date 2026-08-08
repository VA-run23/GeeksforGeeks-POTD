// Minimum Edge Movements to Connect a Graph

/*
 *    1. The problem asks to determine the minimum number of edges required to connect all nodes in a graph.
 *    2. If the number of edges is less than n-1, it is impossible to connect the graph, return -1.
 *    3. Build an adjacency list from the given edges to represent the graph.
 *    4. Use DFS to traverse the graph and count the number of connected components.
 *    5. Each DFS call marks all nodes in a component as visited.
 *    6. The minimum edges required to connect the graph is (components - 1).
 *    7. Time Complexity: O(n + m), Space Complexity: O(n + m).
 */

class Solution {
  private:
    void dfs(int node, vector<int> adj[], vector<int> &visited) {
        visited[node] = 1;
        for (auto &nbr : adj[node]) {
            if (!visited[nbr])
                dfs(nbr, adj, visited);
        }
    }
  public:
    int minEdgesReq(int n, vector<vector<int>> & edges) {
        // code here
        if (edges.size() < n - 1) return -1;
        vector<int> adj[n];
        vector<int> visited(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                components++;
            }
        }
        return components - 1;
    }
};

// Key Points
// 1. Checks if edges are fewer than n-1, returns -1 if impossible.
// 2. Builds adjacency list for graph representation.
// 3. Uses DFS to explore connected components.
// 4. Each DFS marks nodes in one component as visited.
// 5. Counts total number of connected components.
// 6. Minimum edges required = components - 1.
// 7. Runs in O(n + m) time with O(n + m) space.