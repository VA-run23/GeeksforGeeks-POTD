/*
    1. The function takes a 2D vector dist, where dist[i][j] represents the shortest known distance between nodes i and j.
    2. n stores the number of nodes, and INF represents an arbitrarily large value for unreachable paths.
    3. The algorithm iterates through each node i as an intermediate vertex, checking if using i can shorten paths between pairs (j, k).
    4. If a path from j to k through i exists and improves the distance, update dist[j][k] accordingly.
    5. This triple nested loop ensures every pair of nodes is updated based on every possible intermediate node.
    6. Time Complexity: O(n³), since we iterate through three nested loops over n nodes.
    7. Space Complexity: O(n²), as we store all pairwise shortest paths in the dist matrix.
*/

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        const int INF = 1e8;  

        for (int i = 0; i < n; i++) {  
            for (int j = 0; j < n; j++) {  
                for (int k = 0; k < n; k++) { 
                    if (dist[j][i] != INF && dist[i][k] != INF) { 
                        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
                    }
                }
            }
        }
    }

};