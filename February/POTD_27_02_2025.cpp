/*
This implementation uses two stacks to support basic stack operations.
- push(int x): Adds the element x to the main stack and, if appropriate, to the min stack.
- pop(): Removes the top element from the main stack and, if appropriate, from the min stack.
- peek(): Returns the top element of the main stack.
- getMin(): Returns the minimum element from the min stack.
The min stack tracks the minimum elements for constant-time retrieval.
*/

class Solution {
  public:
    Solution() {
        // code here
    }
    stack<int> mainStack;
    stack<int> minSt;
    // Add an element to the top of Stack
    void push(int x) {
        // code here
         mainStack.push(x);
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
        
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
         if (mainStack.empty()) {
            return;
        }
        if (mainStack.top() == minSt.top()) {
            minSt.pop();
        }
        mainStack.pop();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
          if (mainStack.empty()) {
            return -1;
        }
        return mainStack.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        // code here
        if (minSt.empty()) {
            return -1;
        }
        return minSt.top();
    }
};
