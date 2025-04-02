/*  
    1. The class `Solution` contains functions for Breadth-First Search (BFS) traversal of a graph.  
    2. The `bfs` function initializes necessary data structures and starts BFS from node `0`.  
    3. A queue `q` ensures nodes are explored level by level while maintaining proper order.  
    4. The `visited` vector prevents nodes from being processed multiple times, avoiding cycles.  
    5. Nodes are dequeued one by one, added to the result vector `ans`, and their neighbors are checked.  
    6. If a neighbor hasn’t been visited, it's marked as visited and enqueued for processing.  
    7. Finally, `bfs` returns the `ans` vector containing the BFS traversal result.  
*/  

class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfs(vector<vector<int>> &adj) {
          // Code here
          int n = adj.size();
          queue<int> q;
          vector<bool> visited(n, false);
          vector<int> ans;
  
          q.push(0);
          visited[0] = true;
  
          while (!q.empty()) {
              int node = q.front();
              q.pop();
              ans.push_back(node);
  
  
              for (int nbr : adj[node]) {
                  if (!visited[nbr]) {
                      visited[nbr] = true;
                      q.push(nbr);
                  }
              }
          }
  
          return ans;
      }
  };