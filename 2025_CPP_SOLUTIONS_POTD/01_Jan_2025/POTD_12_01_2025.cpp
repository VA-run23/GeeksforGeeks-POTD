class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        stack<int> st;
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) { 
                int cur = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int diff = i - st.top() - 1;
                ans += (min(arr[st.top()], arr[i]) - arr[cur]) * diff;
            }
            st.push(i);
        }
        return ans;
    }
};
