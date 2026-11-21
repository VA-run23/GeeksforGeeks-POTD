// Smallest Subarray with Sum Greater Than X

/*
 *    1. The problem asks to find the length of the smallest subarray
 *       whose sum is strictly greater than x.
 *
 *    2. Use the sliding window technique with two pointers:
 *       - s = start of window.
 *       - e = end of window.
 *
 *    3. Expand the window by moving e and adding arr[e] to the current sum.
 *
 *    4. Whenever the current sum becomes greater than x,
 *       the current window is a valid candidate.
 *
 *    5. Update the answer with the minimum window length found so far.
 *
 *    6. Shrink the window from the left while the sum remains greater than x.
 *       This helps find the smallest valid window ending at e.
 *
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        // code here

        int s = 0, e = 0;
        int sum = 0;
        int ans = INT_MAX;
        int n = arr.size();

        while (e < n) {
            sum += arr[e];

            while (sum > x) {
                ans = min(ans, e - s + 1);
                sum -= arr[s];
                s++;
            }

            e++;
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};

// Key Points
// 1. Uses sliding window to maintain a contiguous subarray.
// 2. Expands the window until sum becomes greater than x.
// 3. Shrinks the window to minimize its length.
// 4. Every valid window is considered exactly once.
// 5. Tracks the minimum length among all valid windows.
// 6. Returns 0 if no subarray has sum greater than x.
// 7. Runs in O(n) time with O(1) extra space.