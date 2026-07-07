// Largest Unblocked Submatrix

/*
 *    1. Extract blocked cell coordinates into separate row and column lists.
 *    2. Add boundary markers (0 and n+1 for rows, 0 and m+1 for columns).
 *    3. Sort both lists to easily compute gaps between consecutive blocked positions.
 *    4. Find the maximum gap between consecutive blocked rows.
 *    5. Find the maximum gap between consecutive blocked columns.
 *    6. The largest unblocked submatrix area is (maxRowGap - 1) * (maxColGap - 1).
 *    7. Time Complexity: O(k log k), Space Complexity: O(k).
 */

class Solution {
  public:
    int largestArea(int n, int m, int k, vector<vector<int>> &arr) {
        // code here
        vector<int> rows, cols;
        for(auto &cell : arr){
            rows.push_back(cell[0]);
            cols.push_back(cell[1]);
        }

        rows.push_back(0);
        rows.push_back(n+1);
        cols.push_back(0);
        cols.push_back(m+1);

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRowGap = 0, maxColGap = 0;

        for(int i = 1; i < rows.size(); i++){
            maxRowGap = max(maxRowGap, rows[i] - rows[i-1]);
        }
        for(int i = 1; i < cols.size(); i++){
            maxColGap = max(maxColGap, cols[i] - cols[i-1]);
        }

        return (maxRowGap - 1) * (maxColGap - 1);
    }
};

// Key Points
// 1. Blocked cells divide the matrix into smaller submatrices.
// 2. Adding boundaries ensures edge cases are handled correctly.
// 3. Sorting helps compute consecutive gaps efficiently.
// 4. Maximum row gap determines vertical free space.
// 5. Maximum column gap determines horizontal free space.
// 6. Subtracting 1 accounts for blocked boundaries themselves.
// 7. Efficient solution using sorting and gap calculation.