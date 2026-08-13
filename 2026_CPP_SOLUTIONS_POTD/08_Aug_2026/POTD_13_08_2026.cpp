// Longest Path in a Directed Acyclic Graph

/*
 *    1. The problem asks to find the longest path distance from a source node in a DAG.
 *    2. Build an adjacency list with edge weights from the given edges.
 *    3. Initialize distances with -∞ (INT_MIN) to represent unreachable nodes.
 *    4. Use a priority queue (max-heap) to process nodes by current longest distance.
 *    5. For each neighbor v of u, update dist[v] if dist[u] + weight > dist[v].
 *    6. Push updated distances into the priority queue to continue relaxation.
 *    7. Time Complexity: O(V + E log V), Space Complexity: O(V + E).
 */

class Solution {
public:
    virtual vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for (auto v: edges) {
            adj[v[0]].push_back({v[1], v[2]});
        }
        
        vector<int> dist(V, INT_MIN);
        priority_queue<pair<int, int>> pq;
        
        pq.push({0, src});
        dist[src] = 0;
        
        while (!pq.empty()) {
            auto [du, u] = pq.top(); pq.pop();
            
            for (auto z: adj[u]) {
                auto [v, w] = z;
                if (dist[v] < (du + w)) {
                    dist[v] = du + w;
                    pq.push({du + w, v});
                }
            }
        }
        
        return dist;
    }
};

// Key Points
// 1. Constructs adjacency list with weighted edges.
// 2. Initializes distances with INT_MIN for unreachable nodes.
// 3. Uses max-heap priority queue for longest path relaxation.
// 4. Updates dist[v] if a longer path is found.
// 5. Works correctly for DAGs where cycles don’t exist.
// 6. Returns vector of longest distances from source.
// 7. Runs in O(V + E log V) time with O(V + E) space.