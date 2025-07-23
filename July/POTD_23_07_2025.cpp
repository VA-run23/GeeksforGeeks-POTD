/*
    1. This function calculates the sum of all subarray sums of a given array using an optimized prefix sum approach.
    2. First, it builds a prefix sum array where prefix[i] stores the sum of elements from index 0 to i.
    3. Then, for each index i, it adds (i + 1) * prefix[i] to the result, capturing contributions from subarrays ending at i.
    4. It subtracts (n - i - 1) * prefix[i], which corrects overcounting from subarrays that start after i but include prefix[i].
    5. This captures every subarray sum exactly once by balancing contributions from different subarray positions.
    6. Time complexity is O(n): one pass for prefix and one for the weighted summation loop.
    7. Space complexity is O(n) due to the prefix array storing cumulative sums.
*/

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += (i + 1) * prefix[i];
            sum -= (n - i - 1) * prefix[i];
        }

        return sum;
    }
};