// Number of Ways to Arrive at Destination

/*
 *    1. The problem is to count distinct shortest paths from source to destination.
 *    2. Each edge has a weight, so shortest path calculation is required.
 *    3. Dijkstra’s algorithm is used to compute minimum distances efficiently.
 *    4. Alongside distances, we maintain the number of ways to reach each node.
 *    5. If a new shorter path is found, update both distance and ways.
 *    6. If another path with equal distance is found, add to ways modulo 1e9+7.
 *    7. Time Complexity: O((V+E) log V), Space Complexity: O(V+E).
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

// Key Points
// 1. Dijkstra’s algorithm ensures shortest path calculation.
// 2. Ways array tracks number of shortest paths to each node.
// 3. Priority queue optimizes node selection by minimum distance.
// 4. Modulo 1e9+7 prevents integer overflow in path counts.
// 5. Both distance and path count are updated simultaneously.
// 6. Works efficiently for weighted undirected graphs.
// 7. Handles large inputs with up to 100,000 nodes and edges.