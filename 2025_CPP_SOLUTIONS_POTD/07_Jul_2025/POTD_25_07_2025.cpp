/* 
1. This function calculates the max sum of a circular subarray by comparing non-wrap and wrap cases.
2. 'maxKadane' uses Kadane’s algorithm to find the max subarray sum without wrapping.
3. Simultaneously, 'minKadane' finds the min subarray sum to help compute the wrap-around case.
4. 'totalSum' stores the sum of all elements to evaluate the circular subarray: totalSum - minKadane.
5. If all elements are negative (i.e., 'maxKadane' is negative), return 'maxKadane' directly.
6. Otherwise, return the maximum of 'maxKadane' and 'totalSum - minKadane'.
7. Time Complexity: O(n); Space Complexity: O(1) — single pass, constant extra space.
*/

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int totalSum = 0;
        int maxKadane = arr[0]; 
        int currMax = arr[0];
        int minKadane = arr[0]; 
        int currMin = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            currMax = max(arr[i], currMax + arr[i]);
            maxKadane = max(maxKadane, currMax);

            currMin = min(arr[i], currMin + arr[i]);
            minKadane = min(minKadane, currMin);

            totalSum += arr[i];
        }
        totalSum += arr[0]; 

        if (maxKadane < 0) return maxKadane;
        return max(maxKadane, totalSum - minKadane);
    }
};
