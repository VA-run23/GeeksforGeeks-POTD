/*
    1. This C++ class evaluates a postfix expression given as a vector of strings using a stack-based approach.
    2. It iterates through each token in the input; if it's an operator, it pops two operands from the stack and applies the operation.
    3. The result of the operation is pushed back onto the stack; if the token is a number, it's converted and pushed directly.
    4. The helper function 'isOperator' checks if a string is a valid operator (+, -, *, /, ^).
    5. The 'applyOp' function performs the actual arithmetic, including special handling for floor division when signs differ.
    6. The final result of the postfix evaluation is the top element of the stack after processing all tokens.
    7. Time Complexity: O(n), Space Complexity: O(n), where n is the number of tokens in the input vector.
*/

class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<long long> st;

        for (string &s : arr) {
            if (isOperator(s)) {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();
                long long res = applyOp(a, b, s);
                st.push(res);
            } else {
                st.push(stoll(s)); 
            }
        }
        return (int)st.top();
    }

  private:
    bool isOperator(const string &s) {
        return (s == "+" || s == "-" || s == "*" || s == "/" || s == "^");
    }

    long long applyOp(long long a, long long b, const string &op) {
        if (op == "+") return a + b;
        if (op == "-") return a - b;
        if (op == "*") return a * b;
        if (op == "/") {
            long long res = a / b;
            if ((a ^ b) < 0 && a % b != 0) res--;
            return res;
        }
        if (op == "^") return pow(a, b);
        return 0;
    }
};