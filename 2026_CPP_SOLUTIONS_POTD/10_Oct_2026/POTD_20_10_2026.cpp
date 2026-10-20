// Lexicographically Largest Array by Parity Segments

/*
 *    1. The problem asks to obtain the lexicographically largest array by rearranging elements.
 *    2. Elements can only be rearranged within contiguous segments having the same parity.
 *    3. Traverse the array and identify maximal segments of:
 *       - all odd numbers, or
 *       - all even numbers.
 *    4. For each segment, find its ending position by extending while parity remains the same.
 *    5. Sort each parity segment in descending order to maximize the lexicographical order.
 *    6. Repeat the process for all segments until the entire array is processed.
 *    7. Time Complexity: O(n log n), Space Complexity: O(1) excluding sorting space.
 */

class Solution {
	public:
	vector<int> lexicographicallyLargest(vector<int> &arr) {
		// code here
		int i = 0;
		int n = arr.size();

		while (i < n) {

			bool odd = (arr[i] % 2);
			int j = i + 1;

			while ((j < n) && ((arr[j] % 2) == odd))
				j++;

			sort(arr.begin() + i, arr.begin() + j, greater<int>());
			i = j;
		}

		return arr;
	}
};

// Key Points
// 1. Array is divided into contiguous same-parity segments.
// 2. Odd and even segments are processed independently.
// 3. Elements cannot move across parity segment boundaries.
// 4. Descending sort gives the largest lexicographical arrangement.
// 5. Each segment is handled exactly once.
// 6. Uses in-place sorting on every valid segment.
// 7. Produces the lexicographically maximum possible array.