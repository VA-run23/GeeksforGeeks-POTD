/*
        1. This program solves the Stock Span Problem: for each day's price, it finds how many consecutive days before it had prices <= today.
        2. A stack is used to store indices of previous days with higher prices, enabling efficient span calculation.
        3. For each price, we pop from the stack while the top price <= current price, discarding smaller/equal past values.
        4. If the stack is empty after popping, span = i+1 (all previous days are smaller); otherwise span = i - st.top().
        5. The first day always has span = 1, since no previous days exist.
        6. Key fix from earlier queries: handle empty stack correctly (ans[i] = i+1) instead of leaving default value.
        7. Time Complexity: O(n) since each element is pushed/popped once; Space Complexity: O(n) for the stack and result array.
*/

class Solution {
public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, 1);
        st.push(0);
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = i - st.top();
            } else {
                ans[i] = i + 1;
            }

            st.push(i);
        }
        return ans;
    }
};