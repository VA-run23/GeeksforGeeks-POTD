/*
1. This function implements Dijkstra’s algorithm to find the shortest distance 
   from the source node to all other nodes in an undirected weighted graph.
2. It first constructs an adjacency list representation of the graph from the 
   given edges, storing neighbors and their respective edge weights.
3. A distance vector is initialized with `INT_MAX`, representing infinite distance 
   from the source node initially.
4. A priority queue (min-heap) is used to process nodes based on their shortest known 
   distance efficiently.
5. The algorithm iterates through nodes, updating the shortest known distance for each 
   neighbor if a shorter path is found.
6. Each updated node is pushed back into the priority queue to ensure it is processed 
   with its latest shortest distance.
7. After processing all nodes, the function returns the vector containing the shortest 
   distances from the source node to every other node.
*/
class Solution {
    public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          // Code here
  
          vector<vector<pair<int, int>>> adj(V);
          for (auto &edge : edges) {
              adj[edge[0]].push_back({edge[1], edge[2]});
              adj[edge[1]].push_back({edge[0], edge[2]}); 
          }
  
          vector<int> dist(V, INT_MAX);
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  
          dist[src] = 0;
          pq.push({0, src});
  
          while (!pq.empty()) {
              int u = pq.top().second;
              pq.pop();
  
              for (auto &pair : adj[u]) {
                  int v = pair.first;
                  int wt = pair.second;
                  if (dist[u] + wt < dist[v]) {
                      dist[v] = dist[u] + wt;
                      pq.push({dist[v], v});
                  }
              }
          }
          return dist;
      }
  };