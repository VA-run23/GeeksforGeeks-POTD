/*
    1. The function 'romanToDecimal' converts a Roman numeral string to its corresponding integer value.
    2. It iterates through the string and checks for subtraction-based combinations like IV (4), IX (9), XL (40), etc.
    3. If such combinations are found, it adds the corresponding value and skips the next character.
    4. If no such pair is found, it simply adds the value of the current Roman character to the result.
    5. The loop continues until the entire string is parsed and the final integer value is returned.
    6. Time Complexity: O(n), where n is the length of the Roman numeral string.
    7. Space Complexity: O(1), as no extra space is used except a few integer variables.
*/

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && s[i] == 'I' && s[i + 1] == 'V') {
                res += 4;
                i++;
            } else if (i < n - 1 && s[i] == 'I' && s[i + 1] == 'X') {
                res += 9;
                i++;
            } else if (i < n - 1 && s[i] == 'X' && s[i + 1] == 'L') {
                res += 40;
                i++;
            } else if (i < n - 1 && s[i] == 'X' && s[i + 1] == 'C') {
                res += 90;
                i++;
            } else if (i < n - 1 && s[i] == 'C' && s[i + 1] == 'D') {
                res += 400;
                i++;
            } else if (i < n - 1 && s[i] == 'C' && s[i + 1] == 'M') {
                res += 900;
                i++;
            } else if (s[i] == 'I') {
                res += 1;
            } else if (s[i] == 'V') {
                res += 5;
            } else if (s[i] == 'X') {
                res += 10;
            } else if (s[i] == 'L') {
                res += 50;
            } else if (s[i] == 'C') {
                res += 100;
            } else if (s[i] == 'D') {
                res += 500;
            } else if (s[i] == 'M') {
                res += 1000;
            }
        }
        return res;
    }
};