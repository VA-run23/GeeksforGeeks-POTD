/*
    1. We use a sliding window approach to find the longest subarray with at most k zeroes flipped to ones.
    2. 'left' and 'right' pointers define the current window; we expand 'right' while tracking the number of zeroes.
    3. If the number of zeroes exceeds k, we shrink the window from the left until it's valid again.
    4. At each step, we update 'maxLen' to store the maximum length of a valid window.
    5. This ensures we always maintain the longest subarray with at most k flips.
    6. Time Complexity: O(n), since each element is visited at most twice (once by 'right', once by 'left').
    7. Space Complexity: O(1), as we use only a few integer variables and no extra data structures.
*/

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int left = 0, right = 0, zeroCount = 0, maxLen = 0;
        int n = arr.size();

        while (right < n) {
            if (arr[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (arr[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};