// Pyramid Array with Reduce Operations

/*
 *    1. The problem asks to transform an array into a pyramid shape with minimum reductions.
 *    2. Pyramid property:
 *       - Values increase by 1 from left until peak.
 *       - Values decrease by 1 from peak to right.
 *    3. Approach:
 *       - Compute prefix constraints (left[i]) → max height possible at index i from left.
 *       - Compute suffix constraints (right[i]) → max height possible at index i from right.
 *       - At each index, valid pyramid height = min(left[i], right[i]).
 *    4. Find maximum possible pyramid height across all indices.
 *    5. Total reductions = sum(arr) - (maxHeight^2).
 *       - Because pyramid of height h has h^2 elements in total.
 *    6. Edge case: if n ≤ 2, pyramid height is 1 → answer = total - 1.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();
        long long total = 0;
        for (int x : arr) total += x;

        if (n <= 2) return (int)(total - 1);

        vector<int> left(n), right(n);
        left[0] = 1;
        for (int i = 1; i < n; i++)
            left[i] = min(left[i - 1] + 1, arr[i]);

        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
            right[i] = min(right[i + 1] + 1, arr[i]);

        long long maxHeight = 0;
        for (int i = 0; i < n; i++)
            maxHeight = max(maxHeight, (long long)min(left[i], right[i]));

        return (int)(total - maxHeight * maxHeight);
    }
};

// Key Points
// 1. Pyramid height limited by both left and right constraints.
// 2. Precompute left[i] and right[i] arrays.
// 3. Valid height at i = min(left[i], right[i]).
// 4. Max height determines largest pyramid possible.
// 5. Reductions = total sum - h^2.
// 6. Edge case: n ≤ 2 → pyramid height = 1.
// 7. Efficient O(n) solution with O(n) space.