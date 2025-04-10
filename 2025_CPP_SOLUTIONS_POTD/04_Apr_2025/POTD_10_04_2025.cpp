/*
    This function implements Prim’s Algorithm to find the minimum cost 
    to connect all houses using Manhattan Distance.

    1. We initialize minDist (minimum connection cost for each house), 
        vis (to track visited houses), and totalCost (final result).
    2. Start from the first house, setting its minimum distance to 0 
        so it gets considered first.
    3. Iterate n times to find the next house with the least cost 
        and add it to the connected network.
    4. Mark the selected house as visited and add its cost to totalCost.
    5. Update the minimum connection cost for remaining houses based on 
        Manhattan Distance.
    6. Repeat until all houses are connected.
    7. Return totalCost, which represents the minimum cost to connect 
        all houses efficiently.
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