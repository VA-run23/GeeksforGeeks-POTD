/*
    1. This function finds the shortest cycle in an undirected weighted graph using Dijkstra's algorithm.
    2. It first constructs an adjacency list representation of the graph.
    3. Each edge is temporarily removed to check the shortest path between its vertices using Dijkstra's algorithm.
    4. A priority queue helps efficiently compute the shortest distance from one vertex to another.
    5. If the shortest distance between removed edge endpoints exists, it forms a cycle with the edge weight.
    6. The minimum cycle length is continuously updated and returned.
    7. Time complexity: O(E * (V log V)), where E is the number of edges and V is the number of vertices; Space complexity: O(V + E).
*/

class Solution {
  public:
  typedef pair<int, int> pii;
  
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pii>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int minCycle = INT_MAX;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];

            vector<vector<pii>> tempAdj = adj;
            tempAdj[u].erase(
                remove_if(tempAdj[u].begin(), tempAdj[u].end(),
                          [&](pii p) { return p.first == v && p.second == w; }),
                tempAdj[u].end());
            tempAdj[v].erase(
                remove_if(tempAdj[v].begin(), tempAdj[v].end(),
                          [&](pii p) { return p.first == u && p.second == w; }),
                tempAdj[v].end());

            vector<int> dist(V, INT_MAX);
            priority_queue<pii, vector<pii>, greater<pii>> pq;

            dist[u] = 0;
            pq.push({0, u});

            while (!pq.empty()) {
                int d = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                if (d > dist[node]) continue;

                for (auto& it : tempAdj[node]) {
                    int nei = it.first;
                    int wt = it.second;

                    if (dist[nei] > dist[node] + wt) {
                        dist[nei] = dist[node] + wt;
                        pq.push({dist[nei], nei});
                    }
                }
            }

            if (dist[v] != INT_MAX) {
                minCycle = min(minCycle, dist[v] + w);
            }
        }

        return (minCycle == INT_MAX) ? -1 : minCycle;
    }
};