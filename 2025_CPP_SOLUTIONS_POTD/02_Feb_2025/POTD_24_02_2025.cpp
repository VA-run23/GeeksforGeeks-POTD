class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        stack<int> st;
        vector<int> ans(arr.size());

        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = (st.empty()) ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return ans;
    }
};