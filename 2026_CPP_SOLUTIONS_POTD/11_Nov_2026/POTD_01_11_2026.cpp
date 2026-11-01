// Maximum Subarray Sum with One Square Allowed

/*
 *    1. The problem asks to find the maximum subarray sum where at most one element
 *       in the chosen subarray can be squared.
 *
 *    2. Maintain two DP states:
 *       - dp0 = maximum subarray sum ending at current index without using square.
 *       - dp1 = maximum subarray sum ending at current index after using square.
 *
 *    3. For each element x:
 *       - Either start a new subarray with x.
 *       - Or extend the previous subarray.
 *
 *    4. Transition for dp0:
 *       - n0 = max(x, dp0 + x)
 *       - Standard Kadane's algorithm.
 *
 *    5. Transition for dp1:
 *       - Square current element and start new subarray.
 *       - Square current element after a normal subarray.
 *       - Extend an already squared subarray.
 *
 *    6. Formula:
 *       - n1 = max(x*x, dp0 + x*x, dp1 + x)
 *
 *    7. The answer is the maximum among all values of dp0 and dp1 encountered.
 *       Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here

        int dp0 = arr[0];
        int dp1 = arr[0] * arr[0];

        int ans = max(dp0, dp1);

        for (int i = 1; i < arr.size(); i++) {
            int x = arr[i];

            int n0 = max(x, dp0 + x);

            int n1 = max({
                x * x,
                dp0 + x * x,
                dp1 + x
            });

            dp0 = n0;
            dp1 = n1;

            ans = max({ans, dp0, dp1});
        }

        return ans;
    }
};

// Key Points
// 1. Extension of Kadane's Algorithm.
// 2. dp0 tracks subarrays without squaring any element.
// 3. dp1 tracks subarrays after using one square operation.
// 4. At each index, choose between starting fresh or extending.
// 5. Square can be applied to exactly one element in a subarray.
// 6. Answer is the maximum value seen across both states.
// 7. Runs in O(n) time with O(1) extra space.