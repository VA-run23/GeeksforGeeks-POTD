// Max Subarray Sum by Removing At Most One

/*
 *    1. We need to find the maximum sum of a contiguous subarray.
 *    2. The twist is that we are allowed to remove at most one element.
 *    3. Kadane’s algorithm helps us find the maximum subarray sum without removal.
 *    4. To handle removal, we compute forward and backward maximum subarray sums.
 *    5. Forward array stores max sum ending at each index, backward array stores max sum starting at each index.
 *    6. For each index, removing arr[i] gives fw[i-1] + bw[i+1] as a candidate answer.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> fw(n), bw(n);

        fw[0] = arr[0];
        int maxSum = arr[0];
        for (int i = 1; i < n; i++) {
            fw[i] = max(arr[i], fw[i-1] + arr[i]);
            maxSum = max(maxSum, fw[i]);
        }

        bw[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            bw[i] = max(arr[i], bw[i+1] + arr[i]);
        }

        for (int i = 1; i < n-1; i++) {
            maxSum = max(maxSum, fw[i-1] + bw[i+1]);
        }

        return maxSum;
    }
};

// Key Points
// 1. Kadane’s algorithm is the base for solving maximum subarray problems.
// 2. Forward array tracks max subarray sums ending at each index.
// 3. Backward array tracks max subarray sums starting at each index.
// 4. Removing one element bridges fw[i-1] and bw[i+1].
// 5. Answer is max of Kadane’s result and removal-based sums.
// 6. Handles both positive and negative arrays correctly.
// 7. Achieves O(n) time complexity with O(n) extra space.