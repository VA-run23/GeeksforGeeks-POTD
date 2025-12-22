/*
  1. The function `rowWithMax1s` takes a 2D binary array `arr` as input, where each row is sorted in non-decreasing order.
  2. It first checks if the array is empty (`n == 0`), and if so, returns -1 since no rows exist.
  3. Two variables are initialized: `mxr` to store the index of the row with maximum 1s, and `maxOnes` to track the highest count of 1s found so far.
  4. The function iterates through each row using a for loop.
  5. For each row, it uses `accumulate` to sum up the elements (since the row contains only 0s and 1s, the sum equals the number of 1s).
  6. If the current row’s count of 1s is greater than `maxOnes`, it updates both `maxOnes` and `mxr` with the new values.
  7. After checking all rows, the function returns `mxr` (index of the row with maximum 1s), or -1 if no 1s were found.

  Time Complexity: O(n * m) → where n = number of rows, m = number of columns (since each row is traversed fully).  
  Space Complexity: O(1) → only a few variables are used, no extra data structures.
*/

// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        if(n == 0) return -1;

        int mxr = -1;
        int maxOnes = 0;

        for(int i = 0; i < n; i++) {
            int ones = accumulate(arr[i].begin(), arr[i].end(), 0);
            if(ones > maxOnes) {
                maxOnes = ones;
                mxr = i;
            }
        }
        return mxr;
    }
};