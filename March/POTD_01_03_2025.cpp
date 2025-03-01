/*
1. Initialize two stacks: one for strings (B) and one for numbers (num).
2. Iterate through the input string (s) to process each character.
3. If a digit is found, calculate the full number and push it onto the num stack.
4. If '[' is encountered, push the current ans onto the B stack and reset ans.
5. If ']' is encountered, pop from both stacks and repeat the string ans 'count' times.
6. Append the repeated string to the previous part and update ans.
7. Continue until the entire input string is processed, then return the decoded string.
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