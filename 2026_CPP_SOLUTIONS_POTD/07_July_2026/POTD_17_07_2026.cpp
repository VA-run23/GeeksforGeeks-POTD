// Max Absolute Difference of Two Subarrays

/*
 *    1. The problem asks for the maximum absolute difference between sums of two non-overlapping subarrays.
 *    2. Use Kadane’s algorithm to compute maximum and minimum subarray sums from the left side.
 *    3. Similarly, compute maximum and minimum subarray sums from the right side.
 *    4. Store these values in arrays to represent best possible sums up to each index.
 *    5. Traverse the array and calculate differences between left and right subarray sums.
 *    6. Take the maximum of absolute differences across all split points.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int maxDiffSubArrays(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> leftMax(n), leftMin(n), rightMax(n), rightMin(n);
        
        int currMax = arr[0], currMin = arr[0];
        leftMax[0] = arr[0];
        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            currMax = max(arr[i], currMax + arr[i]);
            leftMax[i] = max(leftMax[i - 1], currMax);
            
            currMin = min(arr[i], currMin + arr[i]);
            leftMin[i] = min(leftMin[i - 1], currMin);
        }
        
        currMax = arr[n - 1];
        currMin = arr[n - 1];
        rightMax[n - 1] = arr[n - 1];
        rightMin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            currMax = max(arr[i], currMax + arr[i]);
            rightMax[i] = max(rightMax[i + 1], currMax);
            
            currMin = min(arr[i], currMin + arr[i]);
            rightMin[i] = min(rightMin[i + 1], currMin);
        }
        
        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, abs(leftMax[i] - rightMin[i + 1]));
            ans = max(ans, abs(leftMin[i] - rightMax[i + 1]));
        }
        
        return ans;
    }
};

// Key Points
// 1. Kadane’s algorithm efficiently finds max/min subarray sums.
// 2. Left arrays store best sums up to each index.
// 3. Right arrays store best sums from each index to the end.
// 4. Compare left max with right min and left min with right max.
// 5. Absolute difference ensures both positive and negative cases are covered.
// 6. Non-overlapping condition is naturally handled by split points.
// 7. Linear time and space solution ensures scalability.