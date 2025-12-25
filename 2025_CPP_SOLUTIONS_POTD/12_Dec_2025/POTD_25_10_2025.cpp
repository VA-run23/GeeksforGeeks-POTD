/*
    1. The helper function maxRowIndex finds the row index of the maximum element in a given column by scanning all rows.  
    2. In findPeakGrid, we apply a binary search on columns to efficiently locate a peak element in the 2D matrix.  
    3. For each mid column, we identify the row containing the maximum element using maxRowIndex.  
    4. We then compare this candidate element with its immediate left and right neighbors to check the peak condition.  
    5. If the element is greater than or equal to both neighbors, it qualifies as a peak and we return its coordinates.  
    6. If the left neighbor is larger, we shift the search to the left half; otherwise, we move to the right half.  
    7. Time Complexity: O(n log m), since each column scan takes O(n) and binary search runs O(log m); Space Complexity: O(1), as no extra data structures are used.  
*/

class Solution {
public:
    int maxRowIndex(vector<vector<int>>& mat, int col) {
        int index = 0;
        for (int i = 1; i < mat.size(); i++) {
            if (mat[i][col] > mat[index][col]) {
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = maxRowIndex(mat, mid);

            int left  = (mid > 0)     ? mat[row][mid - 1] : INT_MIN;
            int right = (mid < m - 1) ? mat[row][mid + 1] : INT_MIN;

            if (mat[row][mid] >= left && mat[row][mid] >= right) {
                return {row, mid};
            } else if (left > mat[row][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};