/*
    1. The function cntInRange takes an array arr and a list of queries, each query being a range [a, b].
    2. First, the array arr is sorted to allow efficient binary search operations using lower_bound and upper_bound.
    3. For each query, lower_bound finds the first element >= a, and upper_bound finds the first element > b.
    4. The difference (b - a) gives the count of elements lying within the inclusive range [a, b].
    5. These counts are stored in the result vector ans, one for each query.
    6. Finally, the function returns ans, which contains counts for all queries in order.
    7. Time Complexity: O(n log n + q log n), where n = size of arr and q = number of queries; Space Complexity: O(1) auxiliary (excluding output).
    */

    /* Key Points:
    - Sorting arr ensures binary search works correctly.
    - lower_bound and upper_bound are efficient (logarithmic time).
    - The subtraction of iterators gives the number of elements in range.
    - Handles multiple queries efficiently without scanning the array each time.
*/

class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int> ans;
        int n = queries.size();
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; i++) {
            auto a = lower_bound(arr.begin(), arr.end(), queries[i][0]);
            auto b = upper_bound(arr.begin(), arr.end(), queries[i][1]);
            ans.push_back(b - a); 
        }
        return ans;
    }
};
