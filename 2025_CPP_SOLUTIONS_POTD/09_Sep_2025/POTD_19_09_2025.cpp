/*
    1. This function calculates the minimum number of parentheses insertions needed to make a string valid.
    2. It uses two counters: 'open' to track unmatched '(' and 'insertions' for unmatched ')'.
    3. For each character in the string, if it's '(', we increment 'open'.
    4. If it's ')', we check if there's an unmatched '('. If yes, we match it by decrementing 'open'.
    5. If there's no unmatched '(', we increment 'insertions' to account for a needed '('.
    6. After the loop, 'open' holds unmatched '(', and 'insertions' holds unmatched ')'.
    7. The total insertions required is the sum of both counters: 'insertions + open'.

    Time Complexity: O(n) — we traverse the string once.
    Space Complexity: O(1) — only constant extra space is used.
*/

class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int open = 0, insertions = 0;
        for (char c : s) {
            if (c == '(') {
                open++;
            } else { 
                if (open > 0) {
                    open--; 
                } else {
                    insertions++; 
                }
            }
        }
        return insertions + open;
    }
};