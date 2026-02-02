/*
    1. This function computes the maximum circular subarray sum using Kadane’s algorithm.  
    2. It maintains both maximum subarray sum (maxKadane) and minimum subarray sum (minKadane).  
    3. totalSum stores the sum of all elements in the array.  
    4. maxKadane is found using standard Kadane’s algorithm for maximum subarray sum.  
    5. minKadane is found using Kadane’s algorithm but for minimum subarray sum.  
    6. The circular sum is calculated as totalSum - minKadane, representing wrap-around subarrays.  
    7. Time Complexity: O(n), Space Complexity: O(1).  
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

// Key points:
// - Uses Kadane’s algorithm twice: once for max subarray, once for min subarray.
// - totalSum - minKadane handles circular wrap-around cases.
// - If all elements are negative, return maxKadane directly.
// - Efficient solution with O(n) time and O(1) space.
// - Balances between non-circular and circular subarray cases.
