/* 
  1. This program finds the number of distinct paths from a source node to a destination node in a Directed Acyclic Graph (DAG).
  2. The graph is represented as an adjacency list, where each node points to its connected neighbors.
  3. A depth-first search (DFS) is performed recursively to explore all possible paths from the source to the destination.
  4. A memoization technique (dp array) is used to store intermediate results and avoid redundant computations.
  5. The base case ensures that when the destination node is reached, the path count increments.
  6. For each neighbor of the current node, the function calls DFS and accumulates the path count.
  7. Finally, the computed path count is stored in the dp array and returned to optimize repeated calculations.
*/

class Solution {
  public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<int> dp(V, -1);
        return dfs(adj, dp, src, dest);
    }
    
private:
    int dfs(vector<vector<int>>& adj, vector<int>& dp, int node, int dest) {
        if (node == dest) return 1;
        if (dp[node] != -1) return dp[node];
        
        int count = 0;
        for (int nbr : adj[node]) {
            count += dfs(adj, dp, nbr, dest);
        }
        
        return dp[node] = count;
    }
};
