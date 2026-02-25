/*
    1. This function finds the longest subarray where elements greater than k are in majority.
    2. It uses a prefix sum approach: increment prefix if arr[i] > k, else decrement.
    3. If prefix > 0 at index i, the whole subarray from 0 to i is valid.
    4. Otherwise, it checks if prefix-1 was seen before to form a valid subarray.
    5. An unordered_map stores the earliest index of each prefix value.
    6. The answer is updated whenever a longer valid subarray is found.
    7. Time Complexity: O(n), Space Complexity: O(n).
*/
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size();
        int ans = 0, prefix = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            if (arr[i] > k) prefix++;
            else prefix--;

            if (prefix > 0) {
                ans = i + 1;
            } else {
                if (mp.find(prefix - 1) != mp.end()) {
                    ans = max(ans, i - mp[prefix - 1]);
                }
            }

            if (mp.find(prefix) == mp.end()) {
                mp[prefix] = i;
            }
        }
        return ans;
    }
};

// Key points:
// - Problem reduces to tracking balance of elements > k vs ≤ k.
// - Prefix sum encodes this balance (+1 for >k, -1 for ≤k).
// - If prefix > 0, majority > k exists from start.
// - Otherwise, check earliest prefix-1 occurrence to form valid subarray.
// - Hash map ensures O(1) lookup for prefix indices.
// - Efficient solution: O(n) time, O(n) space.
// - Core idea: transform majority condition into prefix sum positivity.
