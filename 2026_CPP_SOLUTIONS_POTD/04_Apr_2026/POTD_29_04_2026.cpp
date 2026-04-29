// Minimum Swaps Required to Group All 1s Together

/*
 *    1. Count the total number of 1s in the array using accumulate.
 *    2. If there are no 1s, return -1 as grouping is impossible.
 *    3. Use a sliding window of size equal to the total number of 1s.
 *    4. Track the count of 1s inside the current window.
 *    5. Update the maximum count of 1s found in any valid window.
 *    6. The minimum swaps required = total 1s - maximum 1s in a window.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
public:
    int minSwaps(vector<int>& arr) {
        // code here
        int n = arr.size();
        int totalOnes = accumulate(arr.begin(), arr.end(), 0);
        if (totalOnes == 0)
            return -1;
        int c = 0;
        int i = 0, j = 0;
        int ans = 0;
        while (j < n) {
            if (arr[j] == 1)
                c++;
            if (j - i + 1 == totalOnes) {
                ans = max(ans, c);
            } else if (j - i + 1 > totalOnes) {
                while (i <= j && j - i + 1 > totalOnes) {
                    if (arr[i] == 1)
                        c--;
                    i++;
                }
                if (j - i + 1 == totalOnes)
                    ans = max(ans, c);
            }
            j++;
        }
        return totalOnes - ans;
    }
};

// Key Points
// 1. Sliding window ensures efficient traversal.
// 2. Window size equals total number of 1s.
// 3. Maximize 1s in a window to minimize swaps.
// 4. Edge case handled when no 1s exist.
// 5. Linear time complexity ensures scalability.
// 6. Constant space usage makes it memory efficient.
// 7. Uses accumulate for concise counting of 1s.