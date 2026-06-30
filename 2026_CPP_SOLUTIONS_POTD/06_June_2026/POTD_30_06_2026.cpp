// Minimum Insertions and Deletions to Convert One Array to Another

/*
 *    1. We are given two arrays, a and b.
 *    2. The goal is to make array a equal to array b using minimum insertions and deletions.
 *    3. First, store all elements of b in a hash set for quick lookup.
 *    4. Traverse array a, and for elements present in b, build the Longest Increasing Subsequence (LIS).
 *    5. LIS ensures we keep the maximum ordered subsequence common to both arrays.
 *    6. The minimum operations required = (N + M - 2 * LIS length).
 *    7. Time Complexity: O(N log N + M), Space Complexity: O(N + M).
 */

class Solution {
    public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
        // code here
        int N = a.size(), M = b.size();
        vector<int> lis;
        
        unordered_set<int> s;
        for (int i = 0; i < M; i++) {
            s.insert(b[i]);  // use b, not B
        }
        
        for (int i = 0; i < N; i++) {
            if (s.find(a[i]) != s.end()) {  // use a, not A
                auto it = lower_bound(lis.begin(), lis.end(), a[i]);
                if (it == lis.end()) {
                    lis.push_back(a[i]);
                } else {
                    *it = a[i];
                }
            }
        }
        
        return N + M - 2 * (int)lis.size();
    }
};

// Key Points
// 1. Use a hash set for quick membership checks.
// 2. Only consider elements of a that exist in b.
// 3. Build LIS to maximize common subsequence.
// 4. LIS length determines how many elements can be retained.
// 5. Formula: N + M - 2 * LIS length.
// 6. Efficient approach using binary search for LIS.
// 7. Handles large arrays with optimal performance.