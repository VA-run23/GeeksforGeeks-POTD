// Exit Point in a Matrix

/*
 *    1. Start from the top-left corner of the matrix.
 *    2. Maintain a direction variable (0=right, 1=down, 2=left, 3=up).
 *    3. If the current cell is 1, turn right (update direction) and set it to 0.
 *    4. Move in the current direction to the next cell.
 *    5. If the next move goes outside the matrix, return the last valid position.
 *    6. Continue until an exit point is found.
 *    7. Time Complexity: O(n*m), Space Complexity: O(1).
 */

class Solution {
    public:
    vector<int> exitPoint(vector<vector<int>> & mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int i = 0, j = 0;
        int dir = 0;
        
        while (true) {
            if (mat[i][j] == 1) {
                dir = (dir + 1) % 4;
                mat[i][j] = 0;
            }
            
            int ni = i, nj = j;
            
            if (dir == 0)
                nj++;
            else if (dir == 1)
                ni++;
            else if (dir == 2)
                nj--;
            else
                ni--;

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                return {i, j};
            }
            
            i = ni;
            j = nj;
        }
    }
};

// Key Points
// 1. Direction changes only when encountering a 1.
// 2. Matrix cells are updated to 0 after being visited.
// 3. Movement follows right, down, left, up cycle.
// 4. Exit occurs when moving outside matrix boundaries.
// 5. Algorithm ensures no infinite loop by marking visited cells.
// 6. Works for both square and rectangular matrices.
// 7. Efficient with O(1) extra space usage.