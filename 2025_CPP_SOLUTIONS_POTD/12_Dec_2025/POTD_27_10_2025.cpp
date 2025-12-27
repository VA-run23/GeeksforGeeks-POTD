/*
   1. The function 'cLessEq' counts how many elements in the matrix are less than or equal to 'mid'
      by traversing from bottom-left corner using a staircase search approach.
   2. If current element <= mid, all elements above in that column are also <= mid, so add (row+1) to count.
   3. If current element > mid, move one row up to find smaller values.
   4. The function 'kthSmallest' applies binary search on the value range [min, max] of the matrix.
   5. For each mid, it uses 'cLessEq' to count elements <= mid, adjusting search space accordingly.
   6. When count < k, move low up; otherwise shrink high down until low == high, which is the kth smallest.
   7. Time Complexity: O(n * log(max-min)), Space Complexity: O(1).
*/

// Key Points:
// - Matrix rows and columns are sorted, enabling staircase search.
// - Binary search is applied on value range, not indices.
// - 'cLessEq' efficiently counts elements <= mid in O(n).
// - The kth smallest element is found without flattening the matrix.
// - Works for large n (up to 500) within constraints.
// - Combines binary search with matrix properties for optimal solution.
// - Avoids extra space by not storing sorted elements.

class Solution {
  public:
    int cLessEq(vector<vector<int>>& mat, int mid, int n) {
        int cnt = 0;
        int row = n - 1;  
        int col = 0;

        while (row >= 0 && col < n) {
            if (mat[row][col] <= mid) {
                cnt += row + 1; 
                col++;
            } else {
                row--;
            }
        }
        return cnt;
    }

    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = cLessEq(mat, mid, n);

            if (cnt < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};