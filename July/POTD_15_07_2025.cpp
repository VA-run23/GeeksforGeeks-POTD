/*
    1. The function `divby13` checks if a large number represented as a string is divisible by 13.
    2. It maintains a variable `rem` to track the running remainder modulo 13.
    3. For each character `ch` in the string, it updates the remainder using the formula:
        rem = (rem * 10 + digit) % 13.
    4. This simulates long division digit by digit without needing to convert the full number.
    5. At each step, the intermediate number is kept small, ensuring constant space usage.
    6. After processing all digits, if the final remainder is 0, the number is divisible by 13.
    7. Time Complexity: O(n) where n is the string length; Space Complexity: O(1).
*/

class Solution {
  public:
    bool divby13(string &s) {
        // code here
        int rem = 0;
        for (char ch : s) {
            rem = (rem * 10 + (ch - '0')) % 13;
        }
        return rem == 0;
    }
};