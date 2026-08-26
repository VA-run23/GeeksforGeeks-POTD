// Negative Weight Cycle Detection (Bellman-Ford)

/*
 *    1. The problem asks to detect if a graph contains a negative weight cycle.
 *    2. Use Bellman-Ford algorithm which can detect negative cycles.
 *    3. Initialize distances with ∞ (INT_MAX), set source distance = 0.
 *    4. Relax all edges V-1 times to compute shortest paths.
 *    5. After relaxation, check once more: if any edge can still be relaxed, a negative cycle exists.
 *    6. Return true if cycle detected, otherwise false.
 *    7. Time Complexity: O(V*E), Space Complexity: O(V).
 */

class Solution {
public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; 

        // Relax edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative cycle
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                return true;
            }
        }

        return false;
    }
};

// Key Points
// 1. Bellman-Ford detects negative cycles by extra relaxation step.
// 2. Distances initialized to INT_MAX, source = 0.
// 3. Relax edges V-1 times for shortest paths.
// 4. If any edge can still be relaxed, cycle exists.
// 5. Works for directed graphs with negative weights.
// 6. Returns true if cycle detected, else false.
// 7. Runs in O(V*E) time with O(V) space.