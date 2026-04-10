// Sorted Subsequence of Size 3

/*
 *    1. We need to find a subsequence of size 3 in increasing order.
 *    2. The subsequence must be strictly increasing: arr[i] < arr[j] < arr[k].
 *    3. To achieve this, track the smallest element to the left of each index.
 *    4. Also track the largest element to the right of each index.
 *    5. If both exist for an index, we have our subsequence.
 *    6. Return the subsequence immediately when found.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size();
        if (n < 3) return {};

        vector<int> mins(n, -1), maxs(n, -1);

        int minIdx = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[minIdx]) {
                minIdx = i;
                mins[i] = -1;
            } else {
                mins[i] = minIdx;
            }
        }

        int maxIdx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] >= arr[maxIdx]) {
                maxIdx = i;
                maxs[i] = -1;
            } else {
                maxs[i] = maxIdx;
            }
        }

        for (int i = 0; i < n; i++) {
            if (mins[i] != -1 && maxs[i] != -1) {
                return {arr[mins[i]], arr[i], arr[maxs[i]]};
            }
        }

        return {};
    }
};

// Key Points
// 1. The problem asks for a sorted subsequence of size 3.
// 2. We use auxiliary arrays to track left minimums and right maximums.
// 3. If both exist for an index, we have a valid subsequence.
// 4. The algorithm runs in linear time O(n).
// 5. Space complexity is O(n) due to auxiliary arrays.
// 6. Early return ensures efficiency once a subsequence is found.
// 7. Handles edge cases like arrays smaller than size 3.