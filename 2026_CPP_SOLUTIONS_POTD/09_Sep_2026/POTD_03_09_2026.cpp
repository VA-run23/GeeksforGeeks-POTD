// Max Adjacent Differences Sum with 1 Replacements

/*
 *    1. The problem asks to maximize the sum of absolute differences between adjacent elements.
 *    2. You are allowed to replace any element with 1 to maximize the sum.
 *    3. Use dynamic programming with two states:
 *       - low → maximum sum if current element is replaced with 1.
 *       - high → maximum sum if current element is kept as original.
 *    4. Transition:
 *       - newLow = max(low, high + abs(arr[i-1] - 1))
 *       - newHigh = max(low + abs(arr[i] - 1), high + abs(arr[i] - arr[i-1]))
 *    5. Update low and high iteratively for each element.
 *    6. Final answer = max(low, high).
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        int low = 0, high = 0;

        for (int i = 1; i < n; i++) {
            int newLow = max(low, high + abs(arr[i - 1] - 1));
            int newHigh = max(low + abs(arr[i] - 1), high + abs(arr[i] - arr[i - 1]));
            low = newLow;
            high = newHigh;
        }
        return max(low, high);
    }
};

// Key Points
// 1. Tracks two states: replace with 1 or keep original.
// 2. Uses DP to maximize adjacent differences.
// 3. Transition ensures optimal choice at each step.
// 4. Handles edge case when n ≤ 1.
// 5. Updates low/high iteratively across array.
// 6. Final answer is max of both states.
// 7. Runs in O(n) time with O(1) space.