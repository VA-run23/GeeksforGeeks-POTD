// Longest Bitonic Subarray

/*
 *    1. A bitonic subarray is one that first increases and then decreases.
 *    2. Track the last index where the increasing sequence breaks using an array.
 *    3. For each position, store the earliest index where the increasing sequence started.
 *    4. Traverse backwards to find where the decreasing sequence starts.
 *    5. At each step, compute the length of the bitonic subarray using stored indices.
 *    6. Update the maximum length found during traversal.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int bitonic(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> incr(n, 0);
        for (int i = 1; i<n; i++) {
            if (arr[i] >= arr[i - 1])
                incr[i] = incr[i - 1];
            else
                incr[i] = i;
        }
        int curr = n - 1;
        int ans = curr - incr[n - 1] + 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] < arr[i + 1])
                curr = i;
            ans = max(ans, curr - incr[i] + 1);
        }
        return ans;
    }
};

// Key Points
// 1. Bitonic subarray requires both increasing and decreasing parts.
// 2. Store earliest increasing start index for each position.
// 3. Traverse backwards to detect decreasing sequences.
// 4. Use stored indices to compute subarray lengths efficiently.
// 5. Update maximum length dynamically during traversal.
// 6. Handles strictly increasing or strictly decreasing arrays as well.
// 7. Linear time and space solution ensures efficiency.