/*
   1. The code finds the shortest path from node 'a' to node 'b' in a graph with straight and curved edges, 
      allowing at most one curved edge to be used in the path.
   2. It maintains a 'dp' table where 'dp[v][0]' stores shortest distance to node 'v' using only straight edges, 
      and 'dp[v][1]' stores shortest distance with at most one curved edge included.
   3. A priority queue (min-heap) is used to implement Dijkstra’s algorithm, storing tuples of 
      (current cost, flag indicating curved edge usage, current node).
   4. The adjacency list 'adj' stores for each edge both straight ('c1') and curved ('c2') weights, 
      enabling exploration of both possibilities during traversal.
   5. If the current path has not used a curved edge ('flag == 0'), both straight and curved options are explored; 
      otherwise, only straight edges are considered.
   6. The algorithm updates distances in 'dp' and pushes new states into the priority queue until all reachable nodes are processed.
   7. Finally, the minimum of 'dp[b][0]' and 'dp[b][1]' is returned as the shortest path length, 
      or '-1' if no valid path exists.

   Time Complexity: O((V + E) log V) → Dijkstra’s complexity with two states per node.  
   Space Complexity: O(V + E) → adjacency list + dp table + priority queue.
*/

class Solution {
public:
    int shortestPath(int V, int a, int b, vector<vector<int>>& edges) {
        // code here
        vector<vector<long long>> dp(V, vector<long long>(2, INT_MAX));
        priority_queue<tuple<long long, long long, long long>,
                       vector<tuple<long long, long long, long long>>,
                       greater<>>
            pq;
        pq.push({0, 0, a});
        vector<vector<tuple<long long, long long, long long>>> adj(V);
        for (int i = 0; i < edges.size(); i++) {
            long long x = edges[i][0];
            long long y = edges[i][1];
            long long c1 = edges[i][2];
            long long c2 = edges[i][3];
            adj[x].push_back({y, c1, c2});
            adj[y].push_back({x, c1, c2});
        }
        dp[a][0] = 0;
        dp[a][1] = 0;
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            long long cost = get<0>(x);
            long long flag = get<1>(x);
            long long node = get<2>(x);
            for (auto itr : adj[node]) {
                long long j = get<0>(itr);
                long long c1 = get<1>(itr);
                long long c2 = get<2>(itr);
                if (flag == 0) {
                    long long ans1 = cost + c1;
                    long long ans2 = cost + c2;
                    if (ans2 < dp[j][1]) {
                        dp[j][1] = ans2;
                        pq.push({ans2, 1, j});
                    }
                    if (ans1 < dp[j][0]) {
                        dp[j][0] = ans1;
                        pq.push({ans1, 0, j});
                    }

                } else {
                    long long ans1 = cost + c1;
                    if (ans1 < dp[j][1]) {
                        dp[j][1] = ans1;
                        pq.push({ans1, 1, j});
                    }
                }
            }
        }
        int x = min(dp[b][0], dp[b][1]);
        if (x >= INT_MAX) {
            return -1;
        }
        return x;
    }
};