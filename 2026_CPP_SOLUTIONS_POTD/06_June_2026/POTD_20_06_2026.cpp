// Last Digit of a^b

/*
 *    1. The problem is to find the last digit of a^b for large numbers.
 *    2. Direct computation is not feasible due to the size of numbers.
 *    3. The last digit of powers follows cyclic patterns depending on the base.
 *    4. Digits 0, 1, 5, and 6 are constant regardless of exponent.
 *    5. Digits 2, 3, 7, and 8 follow a cycle of length 4.
 *    6. Digits 4 and 9 follow a cycle of length 2.
 *    7. Time Complexity: O(1), Space Complexity: O(1).
 */

class Solution {
    public:
    int getLastDigit(string& a, string& b) {
        // code here
        int lt = a.back() - '0';
        if (lt == 0 || lt == 1 || lt == 5 || lt == 6)return lt;
        if (b.size() == 1 && b.back()
             == '0')return 1;
        if (lt == 2 || lt == 3 || lt == 7 || lt == 8) {
            int last = 0;
            last += (b.back() - '0');
            if (b.size() >1) {
                last += 10 * (b[b.size() - 2] - '0');
            }
            if (last%4 == 1)return lt;
            else if (last%4 == 2) {
                if (lt %2 == 0)return 4;
                else
                    return 9;
            } else if (last%4 == 3) {
                if (lt == 2)return 8;
                if (lt == 8)return 2;
                if (lt == 3)return 7;
                if (lt == 7)return 3;
            } else {
                if (lt&1)return 1;
                else
                    return 6;
            }
        } else {
            int bk = b.back() - '0';
            if (bk&1) {
                return lt;
            } else {
                if (lt == 4)return 6;
                else
                    return 1;
            }
        }
    }
};

// Key Points
// 1. The last digit of a^b depends only on the last digit of a.
// 2. Exponent cycles determine the repeating pattern of last digits.
// 3. Digits 0, 1, 5, and 6 are fixed regardless of exponent.
// 4. Digits 2, 3, 7, and 8 cycle every 4 powers.
// 5. Digits 4 and 9 cycle every 2 powers.
// 6. Efficient solution avoids large number computation.
// 7. Runs in constant time and space.