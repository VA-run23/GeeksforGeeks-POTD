/*
1. This class simulates a simple text editor with UNDO and REDO functionality using two stacks and a string.
2. The `append(char x)` method adds a character to the document (`ans`) and pushes it onto the undo stack.
3. The `undo()` method removes the last character from the document, pops it from the undo stack, and pushes it onto the redo stack.
4. The `redo()` method restores the most recently undone character by popping from the redo stack, appending it back to the document, and pushing it into the undo stack.
5. The `read()` method simply returns the current state of the document string.
6. Time Complexity: Each operation (`append`, `undo`, `redo`, `read`) runs in O(1) average time since stack operations and string append/pop_back are constant time.
7. Space Complexity: O(n), where n is the total number of characters stored across the undo and redo stacks plus the string `ans`.
*/

class Solution {
private:
    stack<char> st;
    string ans = "";
    stack<char> undone;

public:
    void append(char x) {
        // append x into document
        ans += x;
        st.push(x);
    }

    void undo() {
        // undo last change
        if (!st.empty()) {
            char x = st.top();
            st.pop();
            undone.push(x);
            int n = ans.size();
            ans = ans.substr(0, n - 1);
        }
    }

    void redo() {
        // redo changes
        if (!undone.empty()) {
            char x = undone.top();
            undone.pop();
            st.push(x);
            ans += x;
        }
    }

    string read() {
        // read the document
        return ans;
    }
};