/*
1. The function 'minCostPath' finds the minimum effort path in a grid, where effort is defined 
   as the maximum absolute difference between adjacent cells along the path.  
2. It uses Dijkstra’s algorithm: each cell is treated as a node, and the edge weight is the 
   absolute difference between the current cell and its neighbor.  
3. A 'dist' matrix stores the minimum effort required to reach each cell, initialized to 'INT_MAX'.  
   The starting cell (0,0) is set to 0.  
4. A min-heap ('priority_queue' with 'greater') ensures we always process the cell with the 
   smallest current effort first.  
5. For each neighbor (up, down, left, right), the new cost is calculated as 
   'max(current_cost, abs(diff))'. If this improves the stored cost, update and push into the queue.  
6. The algorithm stops once the bottom-right cell '(n-1, m-1)' is reached, returning the minimum effort.  
   If unreachable (theoretically impossible here), it returns -1.  
7. Time Complexity: O(n * m * log(n * m)) due to priority queue operations.  
   Space Complexity: O(n * m) for the distance matrix and queue storage.  
*/

/* 🔑 Key Points:
- Problem reduces to finding a minimum bottleneck path in a grid.
- Dijkstra’s algorithm is adapted to minimize the maximum edge weight instead of sum.
- Priority queue ensures optimal exploration order.
- Efficient compared to brute force DFS which is exponential.
*/


class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [cost, pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;

            if (x == n - 1 && y == m - 1)
                return cost; 

            if (cost > dist[x][y])
                continue;

            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    int edge = abs(mat[nx][ny] - mat[x][y]);
                    int newCost = max(cost, edge);

                    if (newCost < dist[nx][ny]) {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
        return -1; 
    }
};