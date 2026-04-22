// Mean of range in array

/*
 *    1. We are given an array and multiple queries, each query specifies a subarray range.
 *    2. The task is to compute the mean (average) of elements in that subarray.
 *    3. To avoid recomputation, we use prefix sums to quickly calculate subarray sums.
 *    4. Prefix sum at index i stores the sum of elements from 0 to i.
 *    5. For each query [l, r], the sum is prefix[r] - prefix[l-1] (if l > 0).
 *    6. Divide this sum by (r - l + 1) to get the mean, integer division gives floor.
 *    7. Time Complexity: O(n + q), Space Complexity: O(1) extra (in-place prefix sum).
 */

class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        vector<int>ans;
        
        for(int i = 1; i<n; i++){
            arr[i] += arr[i-1];
        }
        
        for(auto i: queries){
            int l = i[0], r = i[1];
            ans.push_back( (arr[r] - (l > 0 ? arr[l-1] : 0)) / (r - l + 1) );
        }
        return ans;
    }
};

// Key Points
// 1. Prefix sums allow O(1) subarray sum queries.
// 2. Integer division in C++ truncates, which equals floor for positive numbers.
// 3. Handle l = 0 separately to avoid accessing arr[-1].
// 4. In-place prefix sum saves extra space.
// 5. Works efficiently for large constraints (10^5 elements and queries).
// 6. Avoids recomputation of sums for each query.
// 7. Optimal method: Prefix sums; naive summation per query would be O(n*q).