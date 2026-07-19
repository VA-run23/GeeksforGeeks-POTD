// Mountain Subarray Queries

/*
 *    1. The problem asks whether a given subarray [l, r] is bitonic (first non-decreasing, then non-increasing).
 *    2. Precompute `up` array where up[i] gives the farthest index reachable with non-decreasing sequence starting at i.
 *    3. Precompute `down` array where down[i] gives the farthest index reachable with non-increasing sequence starting at i.
 *    4. For each query [l, r], find the peak index using up[l].
 *    5. If peak covers r directly or down[peak] covers r, then [l, r] is bitonic.
 *    6. Otherwise, the subarray fails the bitonic property.
 *    7. Time Complexity: O(n + q), Space Complexity: O(n).
 */

class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size();
        
        vector<int> up(n), down(n);
        
        up[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1])
                up[i] = up[i + 1];
            else
                up[i] = i;
        }
        
        down[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[i + 1])
                down[i] = down[i + 1];
            else
                down[i] = i;
        }
        
        vector<bool> ans;
        
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            
            int peak = up[l];
            
            if (peak >= r || down[peak] >= r)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        
        return ans;
    }
};

// Key Points
// 1. Bitonic subarray must first be non-decreasing then non-increasing.
// 2. Precompute `up` for longest non-decreasing segments.
// 3. Precompute `down` for longest non-increasing segments.
// 4. Peak index is determined by `up[l]`.
// 5. If peak covers r or down[peak] covers r, query is valid.
// 6. Each query is answered in O(1) using precomputed arrays.
// 7. Efficient solution with preprocessing in linear time.