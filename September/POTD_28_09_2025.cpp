/*
    1. This function finds the longest subarray where the absolute difference between any two elements is ≤ x.
    2. It uses a sliding window approach with two pointers: 'start' and 'end' to track the current subarray.
    3. As 'end' expands, it updates 'minVal' and 'maxVal' to track the smallest and largest values in the window.
    4. If the difference 'maxVal - minVal' exceeds x, it shrinks the window from the left by incrementing 'start'.
    5. After shrinking, it recalculates 'minVal' and 'maxVal' using 'min_element' and 'max_element' for the new window.
    6. It keeps track of the longest valid window using 'resStart' and 'resEnd', updating them when a longer one is found.
    7. Time complexity is O(n²) in worst case due to repeated min/max calculations; space complexity is O(1) excluding output.
*/

class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int start = 0, resStart = 0, resEnd = 0;
        int minVal = arr[0], maxVal = arr[0];

        for (int end = 0; end < n; end++) {
            minVal = min(minVal, arr[end]);
            maxVal = max(maxVal, arr[end]);

            while (maxVal - minVal > x) {
                start++;
                minVal = *min_element(arr.begin() + start, arr.begin() + end + 1);
                maxVal = *max_element(arr.begin() + start, arr.begin() + end + 1);
            }

            if (end - start > resEnd - resStart) {
                resStart = start;
                resEnd = end;
            }
        }
        return vector<int>(arr.begin() + resStart, arr.begin() + resEnd + 1);
    }
};