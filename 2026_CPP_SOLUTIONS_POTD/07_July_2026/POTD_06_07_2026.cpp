// Max Sum Path in Two Arrays

/*
 *    1. Traverse both arrays simultaneously using two pointers.
 *    2. Maintain two running sums (sum1 and sum2) for each array.
 *    3. When elements differ, add the smaller one to its respective sum.
 *    4. When a common element is found, add the maximum of the two sums plus the common element to the result.
 *    5. Reset both sums after switching paths at the common element.
 *    6. After traversal, add the maximum of the remaining sums to the result.
 *    7. Time Complexity: O(m+n), Space Complexity: O(1).
 */

class Solution {
public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // code here
        int m = a.size(), n = b.size();
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0, result = 0;

        while (i < m && j < n) {
            if (a[i] < b[j]) {
                sum1 += a[i++];
            } else if (a[i] > b[j]) {
                sum2 += b[j++];
            } else {
                // Common element found
                result += max(sum1, sum2) + a[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }

        while (i < m) sum1 += a[i++];
        while (j < n) sum2 += b[j++];

        result += max(sum1, sum2);
        return result;
    }
};

// Key Points
// 1. Use two-pointer technique to traverse both arrays.
// 2. Maintain separate sums for each array until a common element is found.
// 3. At a common element, switch paths by adding the maximum accumulated sum.
// 4. Reset sums after switching to avoid double counting.
// 5. Handle remaining elements after one array ends.
// 6. Final result includes the maximum of leftover sums.
// 7. Efficient solution with linear time and constant space.