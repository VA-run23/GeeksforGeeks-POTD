// Dominant Pairs

/*
 *    1. The problem asks to count pairs (i, j) such that:
 *       - i is in the first half of the array
 *       - j is in the second half
 *       - arr[i] >= 5 * arr[j]
 *    2. Split the array into two halves: tmp1 (first half), tmp2 (second half).
 *    3. Sort tmp1 to enable binary search.
 *    4. For each element in tmp2:
 *       - Use lower_bound to find the first index in tmp1 where arr[i] >= 5*arr[j].
 *       - Count all elements from that index to the end.
 *    5. Accumulate counts across all elements in tmp2.
 *    6. Return total count.
 *    7. Time Complexity: O(n log n), Space Complexity: O(n).
 */

class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        int N = arr.size();
        int n = N / 2;
        
        vector<int> tmp1, tmp2;
        
        for (int i = 0; i < n; i++) {
            tmp1.push_back(arr[i]);
        }
        
        for (int i = n; i < N; i++) {
            tmp2.push_back(arr[i]);
        }
        
        sort(tmp1.begin(), tmp1.end());
        
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            int j = lower_bound(tmp1.begin(), tmp1.end(), 5 * tmp2[i]) - tmp1.begin();
            cnt += (n - j);
        }
        
        return cnt;
    }
};

// Key Points
// 1. Split array into two halves.
// 2. Sort first half for binary search.
// 3. For each element in second half, find threshold index.
// 4. Count valid dominant pairs using lower_bound.
// 5. Efficient O(n log n) solution.
// 6. Avoids brute force O(n²) checking.
// 7. Uses binary search for optimal performance.