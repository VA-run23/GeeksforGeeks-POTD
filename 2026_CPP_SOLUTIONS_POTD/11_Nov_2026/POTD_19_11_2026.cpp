// Sort Array by Odd and Even Numbers

/*
 *    1. The problem asks to rearrange the array such that:
 *       - All odd numbers appear first in descending order.
 *       - All even numbers appear later in ascending order.
 *
 *    2. Partition the array into two groups using a pointer idx.
 *       - Odd elements are moved to the front.
 *       - Even elements remain towards the back.
 *
 *    3. Traverse the array once and whenever an odd element is found,
 *       swap it with the element at index idx.
 *
 *    4. After partitioning:
 *       - Elements in range [0, idx-1] are odd.
 *       - Elements in range [idx, n-1] are even.
 *
 *    5. Sort the odd part in descending order using greater<int>().
 *
 *    6. Sort the even part in ascending order using default sort().
 *
 *    7. Time Complexity: O(n log n), Space Complexity: O(1) excluding sorting space.
 */

class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        int n = arr.size();
        int idx = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                swap(arr[i], arr[idx]);
                idx++;
            }
        }

        sort(arr.begin(), arr.begin() + idx, greater<int>());
        sort(arr.begin() + idx, arr.end());
    }
};

// Key Points
// 1. Separates odd and even numbers first.
// 2. Uses in-place partitioning similar to segregating positives/negatives.
// 3. Odd numbers are placed at the beginning of the array.
// 4. Even numbers occupy the remaining positions.
// 5. Odd segment is sorted in descending order.
// 6. Even segment is sorted in ascending order.
// 7. Runs in O(n log n) time with O(1) extra space.