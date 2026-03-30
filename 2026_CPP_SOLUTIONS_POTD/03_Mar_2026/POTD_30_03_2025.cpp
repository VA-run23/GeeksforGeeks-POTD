// Minimum cost to connect all houses in a city

/*
 *    1. The problem is to connect all houses in a city with minimum cost.
 *    2. Each house is represented by its coordinates on a 2D plane.
 *    3. The cost to connect two houses is the Manhattan distance between them.
 *    4. The task reduces to finding a Minimum Spanning Tree (MST).
 *    5. Prim’s algorithm is applied here to build the MST.
 *    6. A priority-based selection ensures minimum cost edges are chosen.
 *    7. Time Complexity: O(n^2), Space Complexity: O(n)
 */

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> vis(n, false);
        int totalCost = 0;
    
        minDist[0] = 0; 
        
        for (int i = 0; i < n; i++) {
            int u = -1;

            for (int j = 0; j < n; j++)
                if (!vis[j] && (u == -1 || minDist[j] < minDist[u]))
                    u = j;
            
            vis[u] = true;
            totalCost += minDist[u];
    
            for (int v = 0; v < n; v++) {
                if (!vis[v]) {
                    int cost = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    minDist[v] = min(minDist[v], cost);
                }
            }
        }
    
        return totalCost;
    }
};

// Key Points
// 1. The problem is essentially an MST problem.
// 2. Manhattan distance is used as edge weight.
// 3. Prim’s algorithm is implemented here.
// 4. Greedy selection ensures minimum cost edges.
// 5. minDist array tracks shortest edge to each node.
// 6. vis array ensures nodes are not revisited.
// 7. Complexity is O(n^2), suitable for moderate input sizes.