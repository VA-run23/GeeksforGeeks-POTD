// Successful Binary Searches Irrespective of Pivot

/*
 *    1. The problem asks to count elements that will always be found by binary search regardless of the pivot in a rotated sorted array.
 *    2. An element is always found if all elements to its left are smaller and all elements to its right are greater.
 *    3. Build a prefix maximum array dpL where dpL[i] stores the maximum value from index 0 to i.
 *    4. Build a suffix minimum array dpR where dpR[i] stores the minimum value from index i to n-1.
 *    5. For each element arr[i], check whether:
 *       - arr[i] >= dpL[i-1]
 *       - arr[i] <= dpR[i+1]
 *    6. Handle boundary elements separately since they have only one side to validate.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        // code here
        int n = arr.size();

        if (n == 1)
            return 1;

        vector<int> dpL = arr, dpR = arr;

        for (int i = 1; i < n; i++) {
            dpL[i] = max(dpL[i], dpL[i - 1]);
            dpR[n - 1 - i] = min(dpR[n - 1 - i], dpR[n - i]);
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (i > 0 && i < n - 1) {
                if (arr[i] >= dpL[i - 1] && arr[i] <= dpR[i + 1])
                    count++;
            }
            else if (i == 0 && arr[0] <= dpR[1]) {
                count++;
            }
            else if (i == n - 1 && arr[n - 1] >= dpL[n - 2]) {
                count++;
            }
        }

        return count;
    }
};

// Key Points
// 1. Uses prefix maximum and suffix minimum arrays.
// 2. dpL[i] stores maximum value seen from the left.
// 3. dpR[i] stores minimum value seen from the right.
// 4. A valid element must be greater than all left elements.
// 5. A valid element must be smaller than all right elements.
// 6. Boundary elements require only one-sided verification.
// 7. Runs in O(n) time with O(n) extra space.