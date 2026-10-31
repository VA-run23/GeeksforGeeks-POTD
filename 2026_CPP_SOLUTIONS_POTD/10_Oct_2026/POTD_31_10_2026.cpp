// Minimize Difference After Removing K Consecutive Elements

/*
 *    1. The problem asks to remove exactly k consecutive elements such that
 *       the difference between the maximum and minimum of the remaining elements is minimized.
 *
 *    2. Build prefix arrays:
 *       - prefMin[i] = minimum value from arr[0...i]
 *       - prefMax[i] = maximum value from arr[0...i]
 *
 *    3. Build suffix arrays:
 *       - suffMin[i] = minimum value from arr[i...n-1]
 *       - suffMax[i] = maximum value from arr[i...n-1]
 *
 *    4. Consider every possible subarray of length k to remove.
 *       - Let removed segment be [i ... i+k-1].
 *
 *    5. The remaining array consists of:
 *       - Left part: [0 ... i-1]
 *       - Right part: [i+k ... n-1]
 *
 *    6. Use prefix and suffix arrays to quickly find:
 *       - Minimum value among remaining elements.
 *       - Maximum value among remaining elements.
 *
 *    7. Compute (max - min) for each removal and return the minimum value.
 *       Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
	public:
	int minDiff(int k, vector<int> &arr) {
		// code here

		int n = arr.size();

		vector<int> prefMin(n), prefMax(n);
		vector<int> suffMin(n), suffMax(n);

		prefMin[0] = prefMax[0] = arr[0];

		for (int i = 1; i < n; i++) {
			prefMin[i] = min(prefMin[i - 1], arr[i]);
			prefMax[i] = max(prefMax[i - 1], arr[i]);
		}

		suffMin[n - 1] = suffMax[n - 1] = arr[n - 1];

		for (int i = n - 2; i >= 0; i--) {
			suffMin[i] = min(suffMin[i + 1], arr[i]);
			suffMax[i] = max(suffMax[i + 1], arr[i]);
		}

		int ans = INT_MAX;

		for (int i = 0; i <= n - k; i++) {
			int left = i - 1;
			int right = i + k;

			int mn = INT_MAX;
			int mx = INT_MIN;

			if (left >= 0) {
				mn = min(mn, prefMin[left]);
				mx = max(mx, prefMax[left]);
			}

			if (right < n) {
				mn = min(mn, suffMin[right]);
				mx = max(mx, suffMax[right]);
			}

			ans = min(ans, mx - mn);
		}

		return ans;
	}
};

// Key Points
// 1. Removes every possible window of size k.
// 2. Prefix arrays store min/max values on the left.
// 3. Suffix arrays store min/max values on the right.
// 4. Remaining elements are formed by combining left and right parts.
// 5. Min and max are obtained in O(1) for each removal.
// 6. Tracks the minimum possible difference.
// 7. Runs in O(n) time with O(n) extra space.