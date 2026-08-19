// Triplets with Sum in Range

/*
 *    1. The problem asks to count triplets (i, j, k) such that arr[i] + arr[j] + arr[k] lies in [l, r].
 *    2. Sort the array to enable two-pointer technique.
 *    3. Define helper function count(arr, range) → counts triplets with sum < range.
 *    4. For each i, fix arr[i], then use two pointers j and k to find valid pairs.
 *    5. If arr[i] + arr[j] + arr[k] < range, all pairs between j and k are valid → add (k - j).
 *    6. Otherwise, decrement k to reduce sum.
 *    7. Final answer = count(arr, r+1) - count(arr, l).
 */

class Solution {
public:
    int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        auto count = [&](vector<int> &arr, int range) {
            int n = arr.size();
            int cnt = 0;
            for (int i = 0; i < n - 2; i++) {
                int j = i + 1;
                int k = n - 1;
                while (j < k) {
                    int temp = arr[i] + arr[j] + arr[k];
                    if (temp < range) {
                        cnt += (k - j);
                        j++;
                    } else {
                        k--;
                    }
                }
            }
            return cnt;
        };
        sort(arr.begin(), arr.end());
        return count(arr, r + 1) - count(arr, l);
    }
};

// Key Points
// 1. Sorts array for two-pointer traversal.
// 2. Helper function counts triplets with sum < range.
// 3. Fixes one element, uses two pointers for remaining pair.
// 4. Adds (k - j) when sum < range since all pairs between j and k are valid.
// 5. Decrements k when sum ≥ range.
// 6. Answer = count(r+1) - count(l) to capture range [l, r].
// 7. Runs in O(n²) time with O(1) extra space.