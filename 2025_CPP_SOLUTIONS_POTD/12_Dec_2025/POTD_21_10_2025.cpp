/*
   1. The function `countXInRange` takes a sorted array `arr` and a list of queries, 
      where each query is of the form [l, r, x] meaning "count occurrences of x in arr[l...r]".
   2. For each query, we extract the left index `l`, right index `r`, and target value `x`.
   3. We use `lower_bound` to find the first position in the subarray [l...r] where `x` could appear.
   4. We use `upper_bound` to find the position just after the last occurrence of `x` in [l...r].
   5. The difference `(up - low)` gives the count of `x` in the specified subarray.
   6. This count is stored in the result vector for each query.
   7. Finally, the function returns the result vector containing counts for all queries.
      → Time Complexity: O(Q * logN), where Q = number of queries, N = size of array.
      → Space Complexity: O(Q) for storing results, aside from input storage.
*/

/* Key Points:
- Queries are processed independently, each using binary search (`lower_bound` & `upper_bound`).
- Efficient because binary search works in O(logN) rather than scanning the subarray.
- Works only because the array is sorted (binary search requires sorted input).
*/

class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int> result;
        for (const auto& q : queries) {
            int l = q[0], r = q[1], x = q[2];
            auto low = lower_bound(arr.begin() + l, arr.begin() + r + 1, x);
            auto up = upper_bound(arr.begin() + l, arr.begin() + r + 1, x);
            result.push_back(up - low);
        }
        return result;
    }
};