/*
    1. This function aims to find the minimum number of K-length consecutive bit flips needed to make all elements in a binary array equal to 1.
    2. It uses a sliding window approach with a helper array 'isFlipped' to track where flips start, and a running count 'flipCount' to track active flips.
    3. At each index 'i', if the current bit (after considering flips) is 0, a flip is needed starting at 'i'.
    4. If flipping at 'i' would exceed the array bounds ('i + k > n'), the task is impossible, so return -1.
    5. When a flip is made, mark 'isFlipped[i] = 1', increment 'flipCount' and 'flips'.
    6. To maintain the correct flip window, subtract 'isFlipped[i - k]' from 'flipCount' once the window moves past 'k' elements.
    7. Time Complexity: O(n), Space Complexity: O(n) — both linear in the size of the input array.
*/

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        // code here
        int n = arr.size(), flips = 0, flipCount = 0;
        vector<int> isFlipped(n, 0);
    
        for (int i = 0; i < n; ++i) {
            if (i >= k) flipCount -= isFlipped[i - k];
            if ((arr[i] + flipCount) % 2 == 0) {
                if (i + k > n) return -1;
                isFlipped[i] = 1;
                flipCount++;
                flips++;
            }
        }
        return flips;
    }
};