// Largest Number in One Swap

/*
 *    1. The problem is to maximize a number by performing at most one swap of its digits.
 *    2. Traverse the string from right to left to track the maximum digit seen so far.
 *    3. If a smaller digit is found before a larger one, mark indices for a potential swap.
 *    4. The swap ensures the leftmost smaller digit is replaced with the rightmost larger digit.
 *    5. This greedy approach guarantees the largest possible number in one swap.
 *    6. If no beneficial swap is found, the number remains unchanged.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        char maxDigit = '0';
        int maxIndx = -1;
        int l = -1, r = -1;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] > maxDigit) {
                maxDigit = s[i];
                maxIndx = i;
            } else if (s[i] < maxDigit) {
                l = i;
                r = maxIndx;
            }
        }

        if (l != -1) swap(s[l], s[r]);
        return s;
    }
};

// Key Points
// 1. Greedy approach ensures optimal swap.
// 2. Traverse from right to left to track max digit.
// 3. Swap only when a smaller digit precedes a larger one.
// 4. Only one swap is allowed.
// 5. If no swap improves the number, return original.
// 6. Works efficiently in linear time.
// 7. Requires constant extra space.
