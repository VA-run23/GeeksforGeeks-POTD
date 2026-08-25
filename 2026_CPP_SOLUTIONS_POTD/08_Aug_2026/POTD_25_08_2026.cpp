// Minimum Moves to Sort Permutation

/*
 *    1. The problem asks for the minimum number of moves to sort a permutation into increasing order.
 *    2. Idea: find the longest subsequence that is already consecutive and increasing.
 *    3. Use a hash map to track the length of consecutive subsequence ending at each value.
 *    4. For each element arr[i], set mp[arr[i]] = mp[arr[i]-1] + 1.
 *    5. Keep track of the maximum subsequence length found.
 *    6. Answer = n - maxi, since only the remaining elements need to be moved.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        int maxi = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            mp[arr[i]] = mp[arr[i] - 1] + 1;
            maxi = max(maxi, mp[arr[i]]);
        }

        return n - maxi;
    }
};

// Key Points
// 1. Tracks longest consecutive increasing subsequence.
// 2. Uses hash map to extend subsequence ending at arr[i]-1.
// 3. Updates maximum subsequence length dynamically.
// 4. Minimum moves = total size - longest subsequence length.
// 5. Efficient O(n) solution using hash map.
// 6. Works specifically for permutations (unique elements).
// 7. Runs in O(n) time with O(n) space.