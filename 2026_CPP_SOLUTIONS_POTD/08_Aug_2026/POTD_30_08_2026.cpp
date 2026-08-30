// Marks from Ranks

/*
 *    1. The problem asks to find the marks corresponding to given ranks.
 *    2. Each interval [l[i], r[i]] contributes (r[i] - l[i] + 1) marks.
 *    3. Build a prefix array vec where vec[i] = total marks up to interval i-1.
 *    4. For each rank, use binary search (lower_bound) on vec to find the interval containing it.
 *    5. Compute offset = rank - vec[pos-1] - 1 to locate exact mark inside interval.
 *    6. Final mark = l[pos-1] + offset.
 *    7. Time Complexity: O(n + q log n), Space Complexity: O(n).
 */

class Solution {
  public:
    vector<int> getMarks(vector<int>& l, vector<int>& r, vector<int>& rank) {
        // code here
        int n = l.size();
        vector<int> vec(n + 1, 0);

        // Step 1: Build prefix array
        for (int i = 0; i < n; i++)
            vec[i + 1] = vec[i] + (r[i] - l[i]) + 1;

        // Step 2: Answer queries using binary search
        vector<int> res;
        for (auto it : rank) {
            int pos = lower_bound(vec.begin(), vec.end(), it) - vec.begin();
            int offset = it - vec[pos - 1] - 1;
            res.push_back(l[pos - 1] + offset);
        }

        return res;
    }
};

// Key Points
// 1. Prefix array stores cumulative marks count.
// 2. Each interval contributes (r[i] - l[i] + 1).
// 3. Binary search locates interval for each rank.
// 4. Offset finds exact mark inside interval.
// 5. Final mark = l[pos-1] + offset.
// 6. Efficient O(n + q log n) solution.
// 7. Uses O(n) extra space.