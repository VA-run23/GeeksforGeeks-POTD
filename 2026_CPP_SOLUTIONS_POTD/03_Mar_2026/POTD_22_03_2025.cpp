// Rotten Oranges

/*
 *    1. The problem involves a grid with fresh and rotten oranges.
 *    2. Rotten oranges spread rot to adjacent fresh oranges each minute.
 *    3. Use BFS to simulate the spread level by level.
 *    4. Track the number of fresh oranges remaining.
 *    5. Each BFS layer represents one unit of time.
 *    6. If fresh oranges remain after BFS, return -1.
 *    7. Time Complexity: O(n*m), Space Complexity: O(n*m).
 */

class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;
        int fresh = 0, time = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) q.push(make_pair(i, j));
                else if (mat[i][j] == 1) fresh++;
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first, y = p.second;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2; 
                        fresh--;
                        q.push(make_pair(nx, ny)); 
                    }
                }
            }
            time++;         
        }
        return (fresh == 0) ? time : -1;
    }
};

// Key Points
// 1. BFS is ideal for level-by-level spread simulation.
// 2. Queue stores rotten oranges to process.
// 3. Each BFS iteration represents one minute.
// 4. Fresh oranges count ensures termination condition.
// 5. Directions array simplifies neighbor traversal.
// 6. If fresh > 0 after BFS, return -1.
// 7. Efficient solution with O(n*m) complexity.
