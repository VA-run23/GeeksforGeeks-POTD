/*
1. The function checkRedundancy checks if an expression string contains redundant brackets.
2. A stack is used to store operators (+, -, *, /) and opening brackets '(' while traversing the string.
3. When a closing bracket ')' is encountered, the code checks the top of the stack.
4. If the top is '(' immediately, it means there were no operators inside, hence redundant brackets → return true.
5. Otherwise, it pops elements until '(' is found, ensuring that operators existed inside the brackets.
6. After popping operators, the '(' is also removed from the stack, continuing the traversal.
7. If no redundant brackets are found during traversal, the function returns false at the end.

Time Complexity: O(n), where n = length of the string (each character is processed once).
Space Complexity: O(n), due to stack usage in worst case (all characters pushed).

Key Points:
- Redundant brackets mean brackets enclosing nothing or only another bracket without operators.
- Stack helps track operators and brackets efficiently.
- Immediate '(' after ')' indicates redundancy.
- This approach ensures correctness by validating operators inside brackets.
*/

class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        stack<char>st;
        for(auto i: s){
            if(i == '+' || i == '-' || i == '/'|| i == '*' || i == '('){
                st.push(i);
            }else if( i == ')'){
                if(st.top() == '('){
                    return true; // If the top of the stack is an opening bracket '(', then the brackets are redundant
                }else {
                    while(st.top() != '('){
                        st.pop();
                    }
                    st.pop();
                }
            }
            
        }
        return false;
    }
};