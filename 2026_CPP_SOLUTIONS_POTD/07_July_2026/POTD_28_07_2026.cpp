// Shortest Path in 1–2 Graph

/*
 *    1. The problem asks for the shortest path between two nodes
 *       in a graph where edge weights are only 1 or 2.
 *    2. Standard Dijkstra’s algorithm works, but we can optimize:
 *       - Use a deque instead of a priority queue.
 *       - Push nodes to front if edge weight = 1.
 *       - Push nodes to back if edge weight = 2.
 *    3. This is known as 0–1 BFS (adapted for weights 1 and 2).
 *    4. Steps:
 *       - Build adjacency list with (neighbor, weight).
 *       - Initialize distance array with INF, set src = 0.
 *       - Use deque to process nodes.
 *       - Update distances and push accordingly.
 *    5. Return shortest distance to dest, or -1 if unreachable.
 *    6. Time Complexity: O(V + E), Space Complexity: O(V + E).
 */

class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }

        // Distance array
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // Deque for 0-1 BFS style traversal
        deque<int> dq;
        dq.push_back(src);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            for (auto &edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    if (w == 1) dq.push_front(v);
                    else dq.push_back(v);
                }
            }
        }

        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};

// Key Points
// 1. Graph edges have weights only 1 or 2.
// 2. Use deque instead of priority queue for efficiency.
// 3. Push front for weight=1, push back for weight=2.
// 4. Guarantees shortest path in O(V+E).
// 5. Cleaner and faster than Dijkstra for this special case.