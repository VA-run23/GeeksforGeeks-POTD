// Split Array into Minimum Subsets

/*
 *    1. The problem asks to split the array into the minimum number of subsets
 *       such that each subset contains consecutive integers.
 *    2. Approach 1 (O(n log n)):
 *       - Sort the array.
 *       - Traverse through elements.
 *       - Whenever arr[i] + 1 != arr[i+1], increment subset count.
 *    3. Approach 2 (O(n)):
 *       - Use a hash set to store elements.
 *       - For each element, check if (element+1) exists.
 *       - If not, it means this element ends a consecutive chain → increment count.
 *    4. Both approaches give the same result, but the hash set method is faster.
 */

class Solution {
  public:
    // O(n log n) solution
    int minSubsets(vector<int>& arr) {
        int ans = 0, n = arr.size();
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n; i++) {
            if (i == n-1 || arr[i] + 1 != arr[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
  public:
    // O(n) solution using hash set
    int minSubsets(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int ans = 0;
        
        for (auto i : arr) {
            if (!s.count(i + 1)) {
                ans++;
            }
        }
        return ans;
    }
};

// Key Points
// 1. Each subset must contain consecutive integers.
// 2. Sorting + linear scan → O(n log n).
// 3. Hash set lookup → O(n).
// 4. Both approaches are valid; hash set is optimal.