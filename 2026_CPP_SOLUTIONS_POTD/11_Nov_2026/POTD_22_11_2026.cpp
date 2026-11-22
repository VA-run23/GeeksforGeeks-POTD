// Longest Subarray with Sum Divisible by K

/*
 *    1. The problem asks to find the length of the longest subarray
 *       whose sum is divisible by k.
 *
 *    2. Use prefix sums and store the first occurrence of each remainder.
 *
 *    3. Let prefixSum be the sum of elements from index 0 to i.
 *       Compute remainder:
 *       rem = ((prefixSum % k) + k) % k.
 *
 *    4. If the same remainder appears again, then the subarray between
 *       the two indices has a sum divisible by k.
 *
 *    5. Store only the first occurrence of each remainder because it
 *       gives the maximum possible subarray length.
 *
 *    6. Initialize mp[0] = -1 to handle subarrays starting from index 0.
 *
 *    7. Time Complexity: O(n), Space Complexity: O(min(n, k)).
 */

class Solution {
	public:
	int longestSubarrayDivK(vector<int>& arr, int k) {
		// code here

		unordered_map<int, int> mp;

		long long sum = 0;
		int maxLen = 0;

		mp[0] = -1;

		for (int i = 0; i < arr.size(); i++) {
			sum += arr[i];

			int rem = ((sum % k) + k) % k;

			if (mp.find(rem) != mp.end()) {
				maxLen = max(maxLen, i - mp[rem]);
			}
			else {
				mp[rem] = i;
			}
		}

		return maxLen;
	}
};

// Key Points
// 1. Uses prefix sums to process subarray sums efficiently.
// 2. Equal remainders imply a divisible subarray.
// 3. Stores first occurrence of each remainder.
// 4. Handles negative numbers using normalized modulo.
// 5. mp[0] = -1 helps with subarrays starting at index 0.
// 6. Updates the maximum valid subarray length found.
// 7. Runs in O(n) time with O(n) extra space.