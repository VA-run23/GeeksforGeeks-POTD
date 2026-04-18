// Flip Bits to Maximize 1s

/*
 *    1. The problem asks to maximize the number of 1s in an array by flipping a subarray.
 *    2. Flipping means changing 0s to 1s and 1s to 0s in the chosen subarray.
 *    3. The prefix sum array is used to quickly calculate the number of 1s in any subarray.
 *    4. A sliding window approach is applied to track potential subarrays for flipping.
 *    5. The algorithm ensures only beneficial flips are considered by resetting when subarray sum is non-positive.
 *    6. The maximum count of 1s is updated by combining outside 1s and flipped inside 0s.
 *    7. Time Complexity: O(n), Space Complexity: O(n)
 */

class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        vector <int> onesMap(n);
        onesMap[0] = arr[0];
        for (int i = 1; i < n; i++) {
            onesMap[i] = onesMap[i - 1] + arr[i];
        }
        
        int ans = onesMap[n - 1];
        
        int subarray = 0;
        for (int left = 0, right = 0; left < n && right < n; right++) {
            if (arr[right] == 0)
                subarray++;
            else
                subarray--;
                
            if (subarray <= 0) {
                subarray = 0;
                left = right + 1;
                continue;
            }
            
            int outOnes = onesMap[n - 1] - 
                (onesMap[right] - (left == 0 ? 0 : onesMap[left - 1]));
                
            int inside = (right - left + 1) -
                (onesMap[right] - (left == 0 ? 0 : onesMap[left - 1]));
            ans = max(ans, outOnes + inside);
        }
        
        return ans;
    }
};

// Key Points
// 1. Problem reduces to finding a subarray with maximum difference between 0s and 1s.
// 2. Prefix sums help in quick subarray calculations.
// 3. Sliding window ensures efficient traversal.
// 4. Resetting subarray when sum ≤ 0 avoids unnecessary flips.
// 5. The answer combines outside 1s with flipped inside 0s.
// 6. Works in linear time, suitable for large inputs.
// 7. Space optimization possible by avoiding prefix sums with Kadane’s algorithm.