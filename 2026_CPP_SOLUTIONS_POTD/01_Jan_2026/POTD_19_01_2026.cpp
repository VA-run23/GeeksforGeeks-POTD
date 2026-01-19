/*
    1. The function removeKdig takes a numeric string and removes k digits to form the smallest possible number.
    2. A stack is used to greedily remove larger digits before smaller ones while traversing the string.
    3. If k is still > 0 after traversal, the remaining digits are popped from the stack (removing from the end).
    4. The digits left in the stack are collected into a string and reversed to restore the correct order.
    5. Leading zeros are removed by skipping them in the final string construction.
    6. If the resulting string is empty after removing zeros, "0" is returned as the smallest valid number.
    7. Time Complexity: O(n) since each digit is pushed/popped at most once; Space Complexity: O(n) for the stack and result string.
*/

// Key Points:
// - Greedy approach ensures smallest lexicographical number.
// - Stack helps efficiently manage digit removal decisions.
// - Handles edge cases like all digits removed, leading zeros, or strictly increasing input strings.

class Solution {
public:
    string removeKdig(string& s, int k) {
        // code here
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];
            while (!st.empty() && st.top() > c && k) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        while (k) {
            st.pop();
            k--;
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int pos = 0;
        while (pos < ans.size() && ans[pos] == '0')
            pos++;
        ans = ans.substr(pos);

        return ans.empty() ? "0" : ans;
    }
};