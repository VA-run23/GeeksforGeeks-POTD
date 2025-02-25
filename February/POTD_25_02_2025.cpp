class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        int ans = 0, i = 0;
        stack<int> st;
        arr.push_back(0); // to get the last value of the histogram
        
        while (i <= n) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int t = st.top();
                int h = arr[t];
                st.pop();
                if (st.empty()) {
                    ans = max(ans, h * i);
                } else {
                    int len = i - st.top() - 1;
                    ans = max(ans, h * len);
                }
            }
            st.push(i);
            i++;
        }
        return ans;
    }
};