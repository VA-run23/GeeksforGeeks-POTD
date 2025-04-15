/*
    1. Initialize distance array d with a large value (1e8) & set source distance to 0.
    2. Perform (V-1) iterations, updating distances if a shorter path is found.
    3. Use a boolean up to track updates and break early if no changes occur.
    4. If after (V-1) iterations, a shorter path is still found, a negative cycle exists.
    5. If a negative cycle is detected, return {-1}; otherwise, return the computed distances.
    6. Time Complexity: O(V * E) (each edge is processed V-1 times in worst case).
    7. Space Complexity: O(V) (only the distance array d is maintained).
*/

class Solution {
    public:
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          // Code here
          vector<int> d(V, 1e8);
          d[src] = 0;
  
          for (int i = 0; i < V - 1; ++i) {
              bool up = false;
              for (auto& e : edges) {
                  int u = e[0], v = e[1], w = e[2];
                  if (d[u] != 1e8 && d[u] + w < d[v]) {
                      d[v] = d[u] + w;
                      up = true;
                  }
              }
              if (!up) break;
          }
  
          for (auto& e : edges)
              if (d[e[0]] != 1e8 && d[e[0]] + e[2] < d[e[1]])
                  return {-1};
  
          return d;
      }
  };