// Minimum Edge Reversals for Path

/*
 *    1. The problem asks for the minimum number of edge reversals required to make a path from src to dst.
 *    2. Idea: Treat the graph as weighted:
 *       - Original edge u → v has cost 0 (no reversal needed).
 *       - Reverse edge v → u has cost 1 (reversal needed).
 *    3. Build adjacency list with pairs (neighbor, cost).
 *    4. Use Dijkstra’s algorithm (priority queue) to find shortest path cost from src to dst.
 *    5. If dst is unreachable, return -1.
 *    6. Otherwise, return minimum cost (number of reversals).
 *    7. Time Complexity: O((n + m) log n), Space Complexity: O(n + m).
 */

class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<pair<int, int>>> adj(n + 1);

        // Step 1: Build graph with costs
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back({v, 0}); // forward edge, no reversal
            adj[v].push_back({u, 1}); // reverse edge, reversal needed
        }

        // Step 2: Dijkstra’s algorithm
        vector<int> dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d != dist[u]) continue;

            for (auto &[v, cost] : adj[u]) {
                if (d + cost < dist[v]) {
                    dist[v] = d + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

// Key Points
// 1. Convert graph into weighted edges (0 for forward, 1 for reverse).
// 2. Use Dijkstra’s algorithm to compute minimum reversals.
// 3. Priority queue ensures shortest path expansion.
// 4. If dst unreachable, return -1.
// 5. Efficient O((n+m) log n) solution.
// 6. Handles directed edges and reversals correctly.
// 7. Elegant graph + shortest path approach.