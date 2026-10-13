// Sort Two Parts Sorted

/*
 * 1. Problem:
 *    - Given an array where two parts (around a break point) are individually sorted.
 *    - Merge them into one fully sorted array.
 *
 * 2. Observation:
 *    - The array is not completely random.
 *    - It consists of two sorted segments.
 *
 * 3. Approach:
 *    - Identify the break point where order changes.
 *    - Treat the array as two sorted halves.
 *
 * 4. Merge process:
 *    - Use two pointers, one for each half.
 *    - Compare elements and push the smaller one into result.
 *
 * 5. Continue merging:
 *    - Advance pointer in whichever half contributed the smaller element.
 *
 * 6. Append remaining elements:
 *    - Once one half is exhausted, append the rest of the other half.
 *
 * 7. Final answer:
 *    - The merged array is fully sorted.
 */

class Solution {
  public:
    void mergeTwoParts(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Find break point
        int breakPoint = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] < arr[i - 1]) {
                breakPoint = i;
                break;
            }
        }

        // Step 2: Merge two sorted halves
        vector<int> result;
        int i = 0, j = breakPoint;
        while (i < breakPoint && j < n) {
            if (arr[i] <= arr[j]) result.push_back(arr[i++]);
            else result.push_back(arr[j++]);
        }

        // Step 3: Append remaining elements
        while (i < breakPoint) result.push_back(arr[i++]);
        while (j < n) result.push_back(arr[j++]);

        // Step 4: Copy back to arr
        arr = result;
    }
};

// 🔑 Key Points
// - Array consists of two sorted parts.
// - Find break point where order changes.
// - Merge using two-pointer technique (like merge sort).
// - Efficient O(n) solution.
// - Space complexity: O(n).
// - Avoids full sort (O(n log n)).
// - Works even if break point is at start or end.