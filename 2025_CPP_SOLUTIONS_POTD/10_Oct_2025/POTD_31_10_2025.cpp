/*
    1. This function finds the length of the shortest cycle in an undirected graph using BFS from each vertex.
    2. It first builds an adjacency list from the given edge list to represent the graph.
    3. For each vertex, it performs BFS while tracking distances and parent nodes to detect cycles.
    4. A cycle is detected when a visited neighbor is not the parent of the current node.
    5. The cycle length is computed as dist[u] + dist[v] + 1 and the minimum is tracked.
    6. If no cycle is found, it returns -1; otherwise, it returns the shortest cycle length.
    7. Time Complexity: O(V * (V + E)) in worst case; Space Complexity: O(V + E) for adjacency list and BFS structures.
*/

class Solution {
public:
    int shortCycle(int V, vector<vector<int>>& edgeList) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto& edge : edgeList) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int minCycle = INT_MAX;

        for (int start = 0; start < V; ++start) {
            vector<int> dist(V, -1);
            vector<int> parent(V, -1);
            queue<int> q;

            dist[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } else if (parent[u] != v) {
                        minCycle = min(minCycle, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return (minCycle == INT_MAX) ? -1 : minCycle;
    }
};