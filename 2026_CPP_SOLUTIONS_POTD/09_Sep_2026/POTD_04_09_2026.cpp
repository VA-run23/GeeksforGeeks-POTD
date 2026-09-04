// Bird and Maximum Fruit Gathering

/*
 *    1. The problem asks to maximize the number of fruits a bird can collect in m consecutive trees.
 *    2. Since trees are arranged circularly, wrap-around must be handled.
 *    3. Use a sliding window of size m to compute fruit sums.
 *    4. Initialize window sum with first m trees.
 *    5. Slide the window across all n trees, adjusting sum by removing leftmost and adding next tree (mod n).
 *    6. Track maximum sum encountered during sliding.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    virtual int maxFruits(vector<int> arr, int m) {
        int ans = 0, n = arr.size();

        int curSum = 0;
        for (int i = 0; i < m; i++) {
            curSum += arr[i];
        }
        ans = max(ans, curSum);

        for (int i = 1; i < n; i++) {
            curSum -= arr[i - 1];
            curSum += arr[(i + m - 1) % n];
            ans = max(ans, curSum);
        }

        return ans;
    }
};

// Key Points
// 1. Sliding window handles consecutive trees efficiently.
// 2. Circular arrangement managed via modulo indexing.
// 3. Initial window sum sets baseline.
// 4. Each step removes one tree and adds next.
// 5. Tracks maximum fruits collected across all windows.
// 6. Runs in O(n) time with O(1) space.
// 7. Elegant solution using sliding window + modulo.