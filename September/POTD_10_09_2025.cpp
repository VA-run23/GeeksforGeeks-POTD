/*
    1. This function finds the lexicographically largest string by swapping at most one pair of digits.
    2. It scans the string from right to left, tracking the maximum digit seen so far and its index.
    3. If a smaller digit is found to the left of a larger digit, it marks both positions for a potential swap.
    4. The swap is only performed if such a pair is found, ensuring the result is strictly larger.
    5. This greedy approach guarantees the earliest beneficial swap for maximum impact.
    6. Time Complexity: O(n), where n is the length of the string — each character is visited once.
    7. Space Complexity: O(1), as only a few integer and character variables are used.
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