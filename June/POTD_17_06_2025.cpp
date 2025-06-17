/*
    1. The function sorts the array to facilitate efficient processing of pile heights. Sorting helps in making optimal decisions for coin removal. (O(n log n))
    2. A prefix sum array is created to allow quick computation of the sum of any subarray, reducing the time complexity of summation operations. (O(n))
    3. The main loop iterates over each pile height and considers it as a target, ensuring all piles are adjusted within the allowed difference `k`. (O(n))
    4. The upper bound index is found using `upper_bound()`, which quickly locates the highest valid pile within `target + k`. (O(log n))
    5. The number of removed coins is calculated efficiently using prefix sums to find excess coins both below and above the valid range. (O(1))
    6. The minimum coins to remove are updated at each step, ensuring the most optimal solution is retained throughout the iterations. (O(n))
    7. The overall time complexity is **O(n log n)** due to sorting and binary search operations, while space complexity is **O(n)** due to the prefix sum array.
*/

class Solution {
public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end()); 
        int n = arr.size();
        vector<int> prefixSum(n, 0);
        
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + arr[i];

        int minCoins = INT_MAX;
        for (int i = 0; i < n; i++) {
            int target = arr[i]; 
            int upperBoundIdx = upper_bound(arr.begin(), arr.end(), target + k) - arr.begin() - 1;
            
            int totalRemoval = (i > 0 ? prefixSum[i - 1] : 0); 
            totalRemoval += (prefixSum[n - 1] - prefixSum[upperBoundIdx]) - (target + k) * (n - 1 - upperBoundIdx);
            
            minCoins = min(minCoins, totalRemoval);
        }

        return minCoins;
    }
};
