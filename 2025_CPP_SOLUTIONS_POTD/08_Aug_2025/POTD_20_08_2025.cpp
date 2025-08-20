/*
1. This function searches for an integer x in a 2D matrix that was originally sorted and then rotated.
2. It treats the matrix as a flattened 1D rotated sorted array and applies a modified binary search.
3. The mid index is mapped back to 2D coordinates using division and modulo operations.
4. If the mid value matches x, the function returns true immediately.
5. It checks which half of the current search space is sorted and narrows the search accordingly.
6. This logic handles the rotation by comparing values at low, mid, and high indices.
7. Time Complexity: O(log(n * m)), Space Complexity: O(1) — efficient binary search with constant space.
*/

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n = mat.size();
        if (n == 0) return false;
        int m = mat[0].size();
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int i = mid / m;
            int j = mid % m;
            int midVal = mat[i][j];

            if (midVal == x) return true;

  
            int lowVal = mat[low / m][low % m];
            int highVal = mat[high / m][high % m];

            if (lowVal <= midVal) {

                if (lowVal <= x && x < midVal) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {

                if (midVal < x && x <= highVal) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};