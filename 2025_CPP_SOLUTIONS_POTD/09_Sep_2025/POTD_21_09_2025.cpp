/*
    1. This code finds the largest rectangle of 1s in a binary matrix by treating each row as a histogram.
    2. The 'getMaxArea' function computes the largest rectangle area in a histogram using a monotonic stack.
    3. It iterates through the histogram, popping from the stack when the current height is less than the top, and calculates area.
    4. The 'maxArea' function builds histogram heights row by row by accumulating consecutive 1s vertically.
    5. For each updated row, it calls 'getMaxArea' to find the maximum rectangle area for that histogram.
    6. The final answer is the maximum of all row-wise histogram areas.
    7. Time Complexity: O(N*M), Space Complexity: O(M), where N is number of rows and M is number of columns.
*/

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;
        int ans = 0;
        for(int i = 0;i<=n;i++){
            while(!st.empty() and (i==n or arr[i]<arr[st.top()])){
                int idx = st.top();
                st.pop();
            
                int idxL  = (!st.empty()) ? st.top():-1;
                int idxR = i;
                
                ans = max(ans, arr[idx]*(idxR-idxL-1));
            }
            st.push(i);
        }
        
        return ans;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(i-1>=0 and mat[i][j] == 1){
                    mat[i][j] += mat[i-1][j];
                }
            }
            ans = max(ans, getMaxArea(mat[i]));
        }
        
        return ans;
    }
};