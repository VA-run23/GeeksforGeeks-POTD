// Minimum Toggles to Partition

/*
 *    1. We are given an array of 0s and 1s.
 *    2. The goal is to partition the array into two parts.
 *    3. One part should contain only 0s, and the other only 1s.
 *    4. We can toggle (flip) elements to achieve this partition.
 *    5. The task is to minimize the number of toggles required.
 *    6. We track prefix sums of 1s and suffix sums of 1s to compute toggles.
 *    7. Time Complexity: O(n), Space Complexity: O(1)
 */

class Solution {
    public:
    int minToggle(vector<int>& arr) {
        // code here
        int n = arr.size(), sum = accumulate(arr.begin(), arr.end(), 0);
        int ans = n - sum, left = 0;
        for (int i = 0; i<n; ++i) {
            left += arr[i];
            sum -= arr[i];
            ans = min(ans, left + n - i - 1 - sum);
        }
        return ans;
    }
};

// Key Points
// 1. Problem reduces to finding optimal partition index.
// 2. Prefix sum tracks 1s on the left side.
// 3. Remaining sum tracks 1s on the right side.
// 4. At each index, compute toggles needed for partition.
// 5. Minimum across all indices gives the answer.
// 6. Efficient solution avoids extra arrays.
// 7. Runs in linear time with constant space.