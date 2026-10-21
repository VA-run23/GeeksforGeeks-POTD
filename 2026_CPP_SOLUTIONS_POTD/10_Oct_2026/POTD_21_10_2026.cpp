// Minimum Sum Subarray

/*
 *    1. The problem asks to find the minimum sum among all possible contiguous subarrays.
 *    2. Use Kadane’s Algorithm variation for minimum subarray sum.
 *    3. Maintain currSum = minimum subarray sum ending at current index.
 *    4. For each element:
 *       - Either start a new subarray from arr[i].
 *       - Or extend the previous subarray by adding arr[i].
 *    5. Update currSum = min(arr[i], currSum + arr[i]).
 *    6. Track the overall minimum subarray sum in minSum.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
	public:
	int minSubarraySum(vector<int> &arr) {
		// code here
		
		int n = arr.size();

		int currSum = arr[0];
		int minSum = arr[0];

		for (int i = 1; i < n; i++) {
			currSum = min(arr[i], currSum + arr[i]);
			minSum = min(minSum, currSum);
		}

		return minSum;
	}
};

// Key Points
// 1. Uses a modified version of Kadane's Algorithm.
// 2. Tracks minimum subarray sum ending at each index.
// 3. Chooses between starting fresh or extending previous subarray.
// 4. currSum stores the local minimum.
// 5. minSum stores the global minimum.
// 6. Works for both positive and negative numbers.
// 7. Runs in linear time with constant extra space.