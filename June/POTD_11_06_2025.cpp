/*
    1. A stack is used to track the sequence of balls.
    2. Iterate through the given color and radius arrays.
    3. If the top of the stack matches the current ball (same color and radius), remove both.
    4. Otherwise, push the current ball onto the stack.
    5. This ensures that consecutive matching pairs are removed efficiently.
    6. The final stack size represents the number of remaining balls.
    7. The approach runs in O(N) time and O(N) space, making it optimal.
*/

class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int, int>> st;
        for (int i = 0; i < color.size(); i++) {
            if (!st.empty() && st.top().first == color[i] && st.top().second == radius[i]) {
                st.pop();
            } else {
                st.push({color[i], radius[i]});
            }
        }
        return st.size();
    }
};
