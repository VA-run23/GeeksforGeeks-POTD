// Implement Atoi

/*
 *    1. Skip leading whitespaces to find the first non-space character.
 *    2. Check for optional sign (+/-) and set the multiplier accordingly.
 *    3. Traverse through digits while they are valid numeric characters.
 *    4. Handle integer overflow by checking before multiplying and adding.
 *    5. Return INT_MAX or INT_MIN if overflow occurs depending on sign.
 *    6. Construct the integer result step by step from digits.
 *    7. Time Complexity: O(n), Space Complexity: O(1)
 */

class Solution {
  public:
    int myAtoi(string &s) {
        // code here
        int sign = 1, r = 0, i = 0;
        while(s[i] == ' ')      i++;     
        if(s[i] == '-' || s[i] == '+'){
            if(s[i++] == '-')       sign = -1;
        }
        while(s[i] >= '0' && s[i] <= '9'){ 
            if(r > INT_MAX/10 || r == INT_MAX/10 && s[i]-'0' > 7)     
                return      sign == 1 ? INT_MAX : INT_MIN;
            r = 10*r+(s[i++]-'0');
        }
        return  r*sign;
    }
};

// Key Points
// 1. Handles leading whitespaces gracefully.
// 2. Supports both positive and negative signs.
// 3. Stops parsing at the first non-digit character.
// 4. Prevents integer overflow using boundary checks.
// 5. Returns clamped values (INT_MAX/INT_MIN) on overflow.
// 6. Efficient single-pass parsing of the string.
// 7. Constant space usage with linear time complexity.