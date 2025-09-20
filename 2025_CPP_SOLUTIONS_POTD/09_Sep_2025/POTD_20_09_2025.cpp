/*
    1. This function finds the length of the longest subarray where every element is less than or equal to the subarray's length.
    2. It uses a monotonic stack to track indices of elements in increasing order, helping identify valid subarray boundaries.
    3. For each element, it simulates a "next greater" scenario by pushing INT_MAX at the end to flush remaining stack entries.
    4. When a greater element is found, it pops from the stack and computes the length of the subarray ending at the current index.
    5. It checks if the popped element is less than or equal to the subarray length; if so, it updates the result.
    6. The stack ensures each index is pushed and popped at most once, making the approach efficient.
    7. Time Complexity: O(n), Space Complexity: O(n) — due to stack usage and single pass through the array.
*/

class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        int res = 0;
        stack<int> st;

        for (int i = 0; i <= n;i++) {
            int curr = (i == n) ? INT_MAX : arr[i];
            while (!st.empty() && arr[st.top()] < curr) {
                int j = st.top(); st.pop();
                int prevIndex = st.empty() ? -1 : st.top();
                int len = i - 1 - prevIndex;
                if (arr[j] <= len) {
                    res = max(res, len);
                }
            }
            if (i < n) st.push(i);
        }

        return res;
    }
};