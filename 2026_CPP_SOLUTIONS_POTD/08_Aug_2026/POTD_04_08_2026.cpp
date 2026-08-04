// Pairs with Difference Less Than K

/*
 *    1. The problem asks to count pairs (i, j) such that |arr[i] - arr[j]| < k.
 *    2. Sorting the array ensures differences can be checked efficiently in order.
 *    3. Use two pointers (l and r) to maintain a sliding window of valid pairs.
 *    4. If the difference between arr[l] and arr[r] is less than k, all pairs with l..r are valid.
 *    5. Add (r - l) to the answer and move r forward to expand the window.
 *    6. If the difference is ≥ k, move l forward to shrink the window.
 *    7. Time Complexity: O(n log n) due to sorting, Space Complexity: O(1).
 */

class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int ans = 0;
        
        int l = 0, r = 1, n = arr.size();
        while (r < n) {
            if (abs(arr[l] - arr[r]) < k) {
                ans += (r - l);
                r++;
            } else {
                l++;
                if(l == r) r++;
            }
        }

        return ans;
    }
};

// Key Points
// 1. Sorts the array to simplify difference checks.
// 2. Uses two pointers to maintain a valid window.
// 3. Adds (r - l) pairs when difference < k.
// 4. Moves r forward to expand the window.
// 5. Moves l forward when difference ≥ k.
// 6. Ensures l never overtakes r by adjusting pointers.
// 7. Efficient O(n log n) solution with constant space.