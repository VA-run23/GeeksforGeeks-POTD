// Pairs with Specific Difference

/*
 *    1. Sort the array to simplify checking consecutive differences.
 *    2. Traverse the array from the end to maximize sums of pairs.
 *    3. Check if the difference between consecutive elements is less than k.
 *    4. If yes, add both elements to the answer.
 *    5. Skip the next element since it’s already paired.
 *    6. Continue until all possible pairs are checked.
 *    7. Time Complexity: O(n log n) due to sorting; Space Complexity: O(1).
 */

class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end()); 
        int ans = 0, n = arr.size();
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] - arr[i - 1] < k) {
                ans += arr[i] + arr[i - 1];
                i--; 
            }
        }
        return ans;
    }
};

// Key Points
// 1. Sorting ensures differences are easy to check.
// 2. Traversing from the end maximizes sum contributions.
// 3. Only consecutive elements are considered for pairing.
// 4. Difference must be strictly less than k.
// 5. Once paired, elements are skipped to avoid reuse.
// 6. Greedy approach ensures maximum sum of valid pairs.
// 7. Efficient with O(n log n) time and O(1) space.