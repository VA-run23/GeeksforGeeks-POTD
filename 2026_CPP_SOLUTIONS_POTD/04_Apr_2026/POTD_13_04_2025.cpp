// Next Smallest Palindrome

/*
 *    1. Start by checking the middle digits and compare left vs right halves.
 *    2. If left half is greater, mirror it to form the palindrome directly.
 *    3. If left half is smaller, break and prepare to increment the middle.
 *    4. Increment the middle digit(s) with carry propagation if needed.
 *    5. Mirror the left half again to ensure palindrome structure.
 *    6. Handle edge case when carry creates an extra digit (e.g., 999 → 1001).
 *    7. Time Complexity: O(n), Space Complexity: O(1) since operations are in-place.
 */

class Solution {
public:
    vector<int> nextPalindrome(vector<int>& num) {
        // code here
        int n = num.size();
        int idx = n / 2 - (n % 2 == 0);
        while (idx >= 0) {
            if (num[idx] > num[n - 1 - idx]) {
                for (int i = 0; i <= n / 2; i++) {
                    num[n - 1 - i] = num[i];
                }
                return num;
            } else if (num[idx] < num[n - 1 - idx])
                break;
            idx--;
        }

        idx = n / 2 - (n % 2 == 0);
        int carry = 1;
        while (idx >= 0) {
            num[idx] = (num[idx] + carry) % 10;
            num[n - 1 - idx] = num[idx];
            carry = (num[idx] % 10 == 0);
            idx--;
        }
        if (num[0] == 0) {
            num[0] = 1;
            num.push_back(1);
        }
        return num;
    }
};

// Key Points
// 1. Compare left and right halves to decide mirroring or increment.
// 2. Mirroring ensures palindrome structure quickly.
// 3. Increment middle digits when left half is smaller.
// 4. Carry propagation is crucial for cases like 1991 → 2002.
// 5. Edge case handling for all 9’s (e.g., 999 → 1001).
// 6. Works in-place without extra space.
// 7. Efficient O(n) solution suitable for large inputs.