/*
    1. This code solves the Knight's Tour problem using backtracking, starting from the top-left corner of an n×n chessboard.
    2. The knight moves are encoded in dx and dy arrays, representing all 8 possible L-shaped moves.
    3. The isSafe function checks if a move is within bounds and the target cell is unvisited (marked -1).
    4. The solve function recursively tries all valid knight moves, marking each visited cell with the current move number.
    5. If a complete tour is found (val == n*n), it returns true; otherwise, it backtracks by resetting the cell to -1.
    6. The knightTour function initializes the board and starts the recursive search from position (0,0).
    7. Time Complexity: O(8^(n²)) in the worst case due to exponential branching; Space Complexity: O(n²) for the board.
*/

class Solution {
  public:
    int dx[8]={2,1,-1,-2,-2,-1,1,2};
    int dy[8]={1,2,2,1,-1,-2,-2,-1};  
    bool isSafe(int x,int y,int n,vector<vector<int>>&ans){
        return (x>=0 && y>=0&& x<n&& y<n&& ans[x][y]==-1);
    }
    bool solve (vector<vector<int>>&ans,int r ,int c,int val,int n){
        if(val==n*n)return true;
       
        for(int k=0;k<8;k++){
            int nx=r+dx[k];
            int ny=c+dy[k];
            if(isSafe(nx,ny,n,ans)){
               ans[nx][ny]=val;
               if(solve(ans,nx,ny,val+1,n))return true;
               ans[nx][ny]=-1;
            }
        }
        return false;
    }
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>>ans(n,vector<int>(n,-1));
        ans[0][0]=0;
        
        if(!solve(ans,0,0,1,n))return {};
        
        return ans;
    }
};