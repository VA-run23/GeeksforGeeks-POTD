/*
    1. This function finds the maximum length of a subarray containing 1s after flipping at most k zeros.  
    2. It uses the sliding window technique with two pointers: left and right.  
    3. As right expands, zeroCount tracks the number of zeros in the current window.  
    4. If zeroCount exceeds k, the left pointer moves forward to shrink the window until valid.  
    5. maxLen is updated with the largest valid window size at each step.  
    6. Time Complexity: O(n), since each element is processed at most twice (once by right, once by left).  
    7. Space Complexity: O(1), as only a few variables are used regardless of input size.  
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

// Key points:
// - Sliding window ensures efficient traversal without re-checking subarrays.
// - zeroCount maintains the constraint of flipping at most k zeros.
// - left pointer shrinks the window when constraint is violated.
// - maxLen captures the longest valid subarray length.
// - Optimal because it avoids brute force checking of all subarrays.
