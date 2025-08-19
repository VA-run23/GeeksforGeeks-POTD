/*
    1. This function computes the farthest index to the right of each element where a smaller value exists.
    2. It first builds a suffix minimum array `pre`, where pre[i] holds the minimum value from index i to the end.
    3. For each index i, it uses binary search (`upper_bound`) to find the first index where the minimum value is less than arr[i].
    4. If such an index is found and it's beyond i, it stores `ind - 1` in the answer array.
    5. The use of `upper_bound` ensures logarithmic search over the suffix minimums.
    6. Time Complexity: O(n log n) due to binary search inside a loop over n elements.
    7. Space Complexity: O(n) for storing the suffix minimums and the result array.
*/

class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> ans(n, -1);
        vector<int> pre(n);

        pre[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            pre[i] = min(arr[i], pre[i + 1]);
        }

        for (int i = 0; i < n - 1; i++) {
            int ind = upper_bound(pre.begin(), pre.end(), arr[i] - 1) - pre.begin();
            if (ind > i) {
                ans[i] = ind - 1;
            }
        }

        return ans;
    }
};