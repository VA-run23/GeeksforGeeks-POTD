/*
   1. Performs Depth-First Search (DFS) to detect cycles in an undirected graph.
   2. Marks the current node as visited and recursively explores its neighbors.
   3. If a visited node is found that isn't the parent, a cycle exists.
   4. Converts the input edge list into an adjacency list for efficient traversal.
   5. Iterates over all nodes to ensure disconnected components are also checked.
   6. Runs DFS for each unvisited node to check for cycles in every component.
   7. Returns true if a cycle is detected; otherwise, returns false.
*/

class Solution {
  public:
    bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, adj, visited)) 
                    return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V]; 
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) 
                    return true;
            }
        }
        return false;
    }
};