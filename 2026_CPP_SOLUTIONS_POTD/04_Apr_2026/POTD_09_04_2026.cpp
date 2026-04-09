// Intersection of Two Sorted Arrays

/*
 *    1. The problem requires finding common elements between two sorted arrays.
 *    2. We use two pointers to traverse both arrays simultaneously.
 *    3. If elements differ, we advance the pointer of the smaller element.
 *    4. If elements match, we add it to the result only if not already present.
 *    5. ans.empty() check prevents calling ans.back() on an empty vector.
 *    6. ans.back() ensures we avoid duplicates by comparing with the last inserted element.
 *    7. Time Complexity: O(m+n), Space Complexity: O(1) excluding output storage.
 */

class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        // code here
        int m = a.size(), n = b.size();
        if (m == 0 || n == 0) return {};

        int i = 0, j = 0;
        vector<int> ans;

        while (i < m && j < n) {
            if (a[i] < b[j]) {
                i++;
            } else if (a[i] > b[j]) {
                j++;
            } else {
                if (ans.empty() || ans.back() != a[i]) {
                    ans.push_back(a[i]);
                }
                i++; j++;
            }
        }

        return ans;
    }
};

// Key Points
// 1. Two-pointer technique leverages sorted arrays efficiently.
// 2. ans.empty() avoids undefined behavior when accessing ans.back().
// 3. ans.back() ensures uniqueness in the result.
// 4. Traversal continues until one array is fully processed.
// 5. Handles duplicate elements gracefully by skipping repeats.
// 6. Works in linear time relative to input sizes.
// 7. Requires no extra data structures beyond the output vector.