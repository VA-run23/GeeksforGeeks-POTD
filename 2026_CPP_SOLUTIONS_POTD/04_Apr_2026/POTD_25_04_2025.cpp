// Reduce Pairs in Array

/*
 *    1. Iterate through the array using a stack to manage elements.
 *    2. Compare current element with the stack’s top to check opposite signs.
 *    3. If absolute values are equal, both cancel out and are removed.
 *    4. If current element is larger in magnitude, pop smaller one and continue.
 *    5. If stack’s top is larger, keep it and skip current element.
 *    6. Push element if no cancellation occurs.
 *    7. Time Complexity: O(n), Space Complexity: O(n) due to stack usage.
 */

class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n == 1) return arr;

        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            bool done = false;
            while (!st.empty()) {
                bool topPos = st.top() > 0;
                bool curPos = arr[i] > 0;
                if (topPos == curPos) break; 
                if (abs(st.top()) == abs(arr[i])) {
                    st.pop();
                    done = true;
                    break;
                } else if (abs(st.top()) < abs(arr[i])) {
                    st.pop(); 
                } else {
                    done = true; 
                    break;
                }
            }
            if (!done) st.push(arr[i]);
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// Key Points
// 1. Stack is used to simulate cancellation of opposite pairs.
// 2. Equal magnitude but opposite signs cancel each other.
// 3. Larger magnitude survives when signs differ.
// 4. Same sign elements are simply stacked.
// 5. Final result is built by reversing stack contents.
// 6. Handles edge case when array has only one element.
// 7. Efficient linear solution with O(n) time and space.