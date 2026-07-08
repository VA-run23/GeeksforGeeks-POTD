// Towers Reaching Both Stations

/*
 *    1. The matrix represents signal strengths of towers in a grid.
 *    2. Station P covers the top and left boundaries, Station Q covers the bottom and right boundaries.
 *    3. A tower can propagate signal to a neighbor only if the neighbor’s strength is less than or equal to the current tower.
 *    4. Use BFS/DFS from boundaries of Station P to mark reachable towers.
 *    5. Similarly, use BFS/DFS from boundaries of Station Q to mark reachable towers.
 *    6. Count towers that are reachable from both Station P and Station Q.
 *    7. Time Complexity: O(n*m), Space Complexity: O(n*m).
 */

class Solution {
  public:
    int countCoordinates(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        if (n == 0) return 0;
        int m = mat[0].size();

        vector<vector<bool>> reachP(n, vector<bool>(m, false));
        vector<vector<bool>> reachQ(n, vector<bool>(m, false));
        queue<pair<int,int>> qP, qQ;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        auto valid = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m;
        };

        auto bfs = [&](queue<pair<int,int>>& q, vector<vector<bool>>& reachable) {
            while (!q.empty()) {
                auto [i, j] = q.front(); q.pop();
                for (auto &d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (valid(ni, nj) && !reachable[ni][nj] && mat[ni][nj] >= mat[i][j]) {
                        reachable[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
        };

        for (int j=0; j<m; j++) { reachP[0][j] = true; qP.push({0,j}); }
        for (int i=0; i<n; i++) { reachP[i][0] = true; qP.push({i,0}); }

        for (int j=0; j<m; j++) { reachQ[n-1][j] = true; qQ.push({n-1,j}); }
        for (int i=0; i<n; i++) { reachQ[i][m-1] = true; qQ.push({i,m-1}); }

        bfs(qP, reachP);
        bfs(qQ, reachQ);

        int countPQ = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (reachP[i][j] && reachQ[i][j]) countPQ++;
            }
        }

        return countPQ;
    }
};

// Key Points
// 1. Station P covers top and left boundaries.
// 2. Station Q covers bottom and right boundaries.
// 3. BFS ensures propagation only to towers with equal or lower strength.
// 4. Two separate BFS traversals mark reachability from each station.
// 5. Towers reachable from both sets are counted.
// 6. Boundary towers are directly connected to their respective stations.
// 7. Efficient solution with linear time and space complexity.