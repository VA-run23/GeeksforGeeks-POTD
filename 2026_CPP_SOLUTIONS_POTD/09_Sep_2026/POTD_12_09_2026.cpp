// Maximum Product Subsequence of Size K

/*
 *    1. The problem asks to find the maximum product of a subsequence of size k.
 *    2. Sort the array to easily access smallest and largest elements.
 *    3. Consider combinations of negatives and positives:
 *       - Taking i smallest elements (possibly negatives).
 *       - Taking (k - i) largest elements.
 *    4. Iterate i from 0 to k, compute product for each combination.
 *    5. Skip invalid cases where not enough elements remain.
 *    6. Track maximum product across all valid combinations.
 *    7. Time Complexity: O(n log n + k), Space Complexity: O(1).
 */

class Solution {
public:
    int maxProduct(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long long best = LLONG_MIN;

        for (int i = 0; i <= k; i++) {
            int j = k - i;
            if (i > n - j) continue;  

            long long product = 1;
            for (int a = 0; a < i; a++) product *= arr[a];
            for (int b = 0; b < j; b++) product *= arr[n - 1 - b];

            best = max(best, product);
        }
        return (int)best;
    }
};

// Key Points
// 1. Sort array to handle negatives and positives systematically.
// 2. Try all splits between smallest and largest elements.
// 3. Product computed for each split of size k.
// 4. Skip invalid splits where indices overlap.
// 5. Track maximum product across all splits.
// 6. Handles negative numbers correctly by pairing them.
// 7. Runs in O(n log n) time with O(1) extra space.