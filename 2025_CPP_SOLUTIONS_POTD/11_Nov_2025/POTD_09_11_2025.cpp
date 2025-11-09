/*
    1. This code solves the "Chocolate Pickup II" problem using dynamic programming with a 3D DP array to simulate two robots moving from (0,0) to (n-1,n-1) simultaneously.
    2. The DP state dp[k][i1][i2] represents the maximum chocolates collected after k steps when robot1 is at (i1, j1) and robot2 is at (i2, j2), where j1 = k - i1 and j2 = k - i2.
    3. It skips invalid positions (out of bounds or blocked cells with -1) and avoids double-counting chocolates when both robots land on the same cell.
    4. For each valid position, it calculates the best previous state from 4 possible transitions and updates the current state with the maximum chocolates.
    5. The loop runs for all steps k from 1 to 2n-2, covering all possible positions both robots can reach in sync.
    6. The final answer is the maximum chocolates collected when both robots reach (n-1,n-1) after 2n-2 steps, or 0 if unreachable.
    7. Time Complexity: O(n³) due to three nested loops over n and k; Space Complexity: O(n³) for the 3D DP array.
*/

class Solution {
  public:
    int chocolatePickup(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        
        if(mat[0][0]==-1 || mat[n-1][n-1]==-1){
            return 0;
        }

        vector<vector<vector<int>>> dp(2*n-1,vector<vector<int>>(n,vector<int>(n,INT_MIN)));

        dp[0][0][0] = mat[0][0];

        for(int k=1; k<2*n-1;k++){
            for(int i1=0;i1<n;i1++){
                for(int i2 = 0;i2<n;i2++){
                    int j1 = k - i1;
                    int j2 = k - i2;

                    if(j1<0 || j1>=n || j2<0 || j2>=n){
                        continue;
                    }
                    if(mat[i1][j1]==-1 || mat[i2][j2]==-1){
                        continue;
                    }

                    int val=mat[i1][j1];
                    if(i1 != i2){ 
                        val+=mat[i2][j2];
                    }
                    
                    int best=INT_MIN;
                    if(i1>0 && i2>0) best = max(best, dp[k-1][i1-1][i2-1]);
                    if(i1>0 && j2>0) best = max(best, dp[k-1][i1-1][i2]);
                    if(j1>0 && i2>0) best = max(best, dp[k-1][i1][i2-1]);
                    if(j1>0 && j2>0) best = max(best, dp[k-1][i1][i2]);

                    if(best!=INT_MIN){
                        dp[k][i1][i2]=best+val;
                    }
                        
                }
            }
        }

        return max(0, dp[2*n-2][n-1][n-1]);
    }
};