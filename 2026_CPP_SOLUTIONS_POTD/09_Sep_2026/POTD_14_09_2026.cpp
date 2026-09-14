// Shortest Path in Matrix with Blocked Neighbors

/*
 *    1. The problem asks to find the shortest path from any cell in the first column to any cell in the last column.
 *    2. A cell is blocked if it is 0 or adjacent to a 0 (up, down, left, right).
 *    3. Preprocess the matrix:
 *       - Mark all 0 cells and their neighbors as blocked (set to 0).
 *       - Remaining cells are valid (set to 1).
 *    4. Perform BFS starting from all valid cells in the first column.
 *    5. BFS explores neighbors in 4 directions, tracking path length.
 *    6. If BFS reaches the last column, return the path length.
 *    7. If no path exists, return -1.
 *    8. Time Complexity: O(n*m), Space Complexity: O(n*m).
 */

class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> matrix(n, vector<int>(m, 1));
        
        // Step 1: Preprocess to block cells
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    matrix[i][j] = 0;
                    int dx[4] = {-1, 0, 1, 0};
                    int dy[4] = {0, 1, 0, -1};
                    
                    for(int k=0; k<4; k++){
                        int newX = dx[k] + i;
                        int newY = dy[k] + j;
                        
                        if(newX >= 0 && newX < n && newY >= 0 && newY < m){
                            matrix[newX][newY] = 0;
                        }
                    }
                }
            }
        }
        
        // Step 2: BFS from first column
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        for(int i=0; i<n; i++){
            if(matrix[i][0] == 1){
                q.push({{i, 0}, 1});
                visited[i][0] = 1;
            }
        }
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            
            int x = p.first.first;
            int y = p.first.second;
            int count = p.second;
            
            if(y == m-1) return count;
            
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
                    
            for(int k=0; k<4; k++){
                int newX = dx[k] + x;
                int newY = dy[k] + y;
                        
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && matrix[newX][newY] == 1 && visited[newX][newY] == 0){
                    q.push({{newX, newY}, count+1});
                    visited[newX][newY] = 1;
                }
            }
        }
        return -1;
    }
};

// Key Points
// 1. Preprocessing blocks all 0 cells and their neighbors.
// 2. BFS explores valid paths from first column.
// 3. Stops when last column is reached.
// 4. Returns shortest path length if exists.
// 5. Returns -1 if no path exists.
// 6. Efficient O(n*m) solution.
// 7. Uses BFS for guaranteed shortest path.