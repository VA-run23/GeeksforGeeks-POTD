/*
1. Initialize the grid dimensions n & m, a queue q for storing rotten oranges, and variables fresh (count of fresh oranges) and time (elapsed minutes).
2. Traverse the grid to find rotten oranges and push their positions into q, while counting the number of fresh oranges.
3. Define direction arrays dx and dy to help traverse the four adjacent cells (up, down, left, right).
4. Perform Breadth-First Search (BFS) using a queue while there are fresh oranges left.
5. For each rotten orange, check its adjacent cells; if the cell contains a fresh orange, rot it, decrement fresh, and push it into q.
6. Increment time after processing all rotten oranges of the current level (simulating time progression).
7. If all fresh oranges are rotten, return time; otherwise, return -1 indicating that some fresh oranges remain unrotted.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& mat) {
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