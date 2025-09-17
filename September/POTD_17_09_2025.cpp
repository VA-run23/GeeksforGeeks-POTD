/*
    1. This function decodes a string with nested patterns like "3[a2[c]]" using two stacks: one for strings and one for repeat counts.
    2. It iterates through the input string 's', parsing digits to form repeat counts and pushing them onto the 'num' stack.
    3. When encountering '[', it pushes the current 'ans' string onto the 'B' stack and resets 'ans' to build the new substring.
    4. Upon encountering ']', it pops the last string from 'B' and the repeat count from 'num', then appends 'ans' to the popped string 'count' times.
    5. If the character is a letter, it simply appends it to the current 'ans' string.
    6. This process continues until the entire string is parsed, and the final decoded string is returned.
    7. Time Complexity: O(n * k), where n is the length of the string and k is the maximum repeat count; Space Complexity: O(n), due to stacks and temporary strings.
*/

class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string> B;
        stack<int> num;
        string ans = "";
        int i = 0;

        while (i < s.size()) {
            if (isdigit(s[i])) {
                int count = 0;
                while (isdigit(s[i])) {
                    count = count * 10 + (s[i] - '0');
                    i++;
                }
                num.push(count);
            } else if (s[i] == '[') {
                B.push(ans);
                ans = "";
                i++;
            } else if (s[i] == ']') {
                string temp = B.top();
                B.pop();
                int count = num.top();
                num.pop();
                
                for (int j = 0; j < count; j++) {
                    temp += ans;
                }
                ans = temp;
                i++;
            } else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};