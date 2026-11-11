// Any Duplicate Within K Distance

/*
 *    1. The problem asks to determine whether there exists a pair of equal elements
 *       whose indices differ by at most k.
 *    2. Use a hash map to store the most recent index of every element.
 *    3. Traverse the array from left to right.
 *    4. If the current element has appeared before, calculate the distance
 *       between the current index and its previous occurrence.
 *    5. If the distance is less than or equal to k, return true immediately.
 *    6. Update the hash map with the latest index of the current element.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            if (mp.count(arr[i])) {
                if (i - mp[arr[i]] <= k)
                    return true;
            }

            mp[arr[i]] = i;
        }

        return false;
    }
};

// Key Points
// 1. Uses a hash map to store the latest occurrence of each element.
// 2. Checks only the nearest previous occurrence of a duplicate.
// 3. Distance is computed as currentIndex - previousIndex.
// 4. Returns true as soon as a valid pair is found.
// 5. Updates index after processing each element.
// 6. Avoids O(n²) brute-force comparisons.
// 7. Runs in O(n) time with O(n) extra space.