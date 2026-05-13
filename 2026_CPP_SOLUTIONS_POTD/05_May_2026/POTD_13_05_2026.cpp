 // Mother Vertex

/*
 *    1. The problem is to find a mother vertex in a directed graph.
 *    2. A mother vertex is a vertex from which all other vertices are reachable.
 *    3. The approach uses Depth First Search (DFS) to explore connectivity.
 *    4. First, we identify a candidate by performing DFS across all unvisited nodes.
 *    5. The last finished vertex in DFS traversal is the candidate mother vertex.
 *    6. We then verify if this candidate can reach all vertices by another DFS.
 *    7. Time Complexity: O(V + E), Space Complexity: O(V) for adjacency list and visited array.
 */

class Solution {
  public:
    
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findMotherVertex(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> visited(V, 0);
        
        int candidate = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                
                candidate = i;
            }
        }

        fill(visited.begin(), visited.end(), 0);

        dfs(candidate, adj, visited);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return -1;
            }
        }

        return candidate;
    }
};

// Key Points
// 1. A mother vertex is one from which all nodes are reachable.
// 2. DFS is used to explore graph connectivity.
// 3. The last finished vertex in DFS is the candidate.
// 4. Verification step ensures candidate reaches all vertices.
// 5. If candidate fails, no mother vertex exists.
// 6. Efficient approach with O(V + E) complexity.
// 7. Uses adjacency list and visited array for space efficiency.