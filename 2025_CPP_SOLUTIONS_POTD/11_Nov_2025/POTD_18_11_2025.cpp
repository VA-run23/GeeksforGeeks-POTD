/*
    1. Build an adjacency list `adj` where each node stores pairs (neighbor, weight) from the given edges.
    2. Initialize `cost` array with large values (1e18) to track shortest distance to each node, and `ways` array to count paths.
    3. Set source node (0) with cost = 0 and ways = 1, meaning one way to start at the source.
    4. Use a min‑heap priority queue (Dijkstra’s algorithm) to always process the node with the smallest current distance.
    5. For each neighbor, if a shorter path is found, update its cost and set ways equal to the parent’s ways.
    6. If another path with equal shortest distance is found, add the parent’s ways to the neighbor’s ways modulo 1e9+7.
    7. Finally, return ways[V‑1], which represents the number of distinct shortest paths to the destination node.
    Time Complexity: O((V + E) log V) due to Dijkstra with priority queue.
    Space Complexity: O(V + E) for adjacency list, cost, and ways arrays.
*/

class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(V);
        for(auto &it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> cost(V, 1e18);
        vector<int> ways(V, 0);
        cost[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > cost[node]) continue;

            for(auto &it : adj[node]) {
                int adjnode = it.first;
                long long wt = it.second;

                if(dis + wt < cost[adjnode]) {
                    cost[adjnode] = dis + wt;
                ways[adjnode] = ways[node];
                    pq.push({cost[adjnode], adjnode});
                }
                else if(dis + wt == cost[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }

        return ways[V-1] % MOD;
    }
};