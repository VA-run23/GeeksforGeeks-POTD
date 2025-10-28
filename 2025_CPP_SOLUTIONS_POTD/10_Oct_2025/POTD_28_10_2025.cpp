/*
    1. This function computes the minimum Manhattan distance from each cell to the nearest cell containing 1 in a binary grid.
    2. It initializes a solution matrix `sol` with INT_MAX and collects all positions of 1s into the `ones` vector.
    3. In the first pass (top-left to bottom-right), it sets distance 0 for cells with 1 and attempts to update distances for 0s using already collected 1s.
    4. In the second pass (bottom-right to top-left), it revisits all 0s and again computes the minimum distance to every 1 to ensure accuracy.
    5. The use of `emplace_back(i, j)` efficiently adds 1-cell coordinates to the `ones` vector without extra copying.
    6. The logic avoids BFS and uses brute-force distance checks, which is acceptable for small to medium grids.
    7. Time Complexity: O(m * n * k), where k is the number of 1s; Space Complexity: O(m * n + k) for the solution matrix and the list of 1s.
*/

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> sol(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> ones;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) {
                    sol[i][j] = 0;
                    ones.emplace_back(i, j);
                }else if(ones.size()){
                    for(auto& one : ones){
                        int dist = abs(one.first - i) + abs(one.second - j);
                        sol[i][j] = min(sol[i][j], dist);
                    }
                }
            }
        }

       
        for(int i = m -1;  i>=0; i--){
            for(int j = n -1; j>=0; j--){
                if(grid[i][j] == 0){
                    for(auto& one : ones){
                        int dist = abs(one.first - i) + abs(one.second - j);
                        sol[i][j] = min(sol[i][j], dist);
                    }
                }
            }
        }

        return sol;
    }
};