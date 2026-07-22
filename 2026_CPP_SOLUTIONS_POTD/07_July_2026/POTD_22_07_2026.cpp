// Minimum Deletions to Make Sorted Sequence

/*
 *    1. The problem asks for the minimum number of deletions required
 *       to make the array strictly increasing.
 *    2. Key idea: Keep the Longest Increasing Subsequence (LIS),
 *       delete the rest.
 *    3. Minimum deletions = n - LIS_length.
 *    4. Use patience sorting + binary search to compute LIS length in O(n log n).
 *    5. Time Complexity: O(n log n), Space Complexity: O(n).
 */

class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        vector<int> lis;
        lis.push_back(arr[0]);

        for (int i = 1; i < n; i++) {
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            if (it == lis.end()) {
                lis.push_back(arr[i]);
            } else {
                *it = arr[i];
            }
        }

        return n - lis.size();
    }
};

// Key Points
// 1. LIS ensures subsequence order is preserved.
// 2. We only need LIS length, not the actual subsequence.
// 3. lower_bound replacement keeps tails minimal for future growth.
// 4. Answer = total elements - LIS length.
// 5. Efficient O(n log n) solution compared to O(n^2) DP LIS.