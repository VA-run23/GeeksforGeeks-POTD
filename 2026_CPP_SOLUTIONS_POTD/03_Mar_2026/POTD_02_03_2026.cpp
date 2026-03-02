/*
    1. This function solves the "Trapping Rain Water" problem using a stack-based approach.
    2. It iterates through the array of bar heights, maintaining indices in a stack to track boundaries.
    3. When a taller bar is found, it pops shorter bars and calculates trapped water between boundaries.
    4. The trapped water is computed as (min(left boundary, right boundary) - height of popped bar) * width.
    5. The width is the horizontal distance between current index and the new stack top minus one.
    6. Time Complexity: O(n), since each element is pushed and popped at most once.
    7. Space Complexity: O(n), due to the stack storing indices of bars.
*/

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

// Key points:
// - The stack stores indices of bars to identify boundaries for trapped water.
// - Water is trapped when a taller bar closes a "valley" formed by shorter bars.
// - The formula uses min(left boundary, right boundary) to ensure correct water height.
// - Width is calculated as the gap between boundaries minus one.
// - Each index is processed at most twice (push and pop), ensuring O(n) time.
// - This is a stack-based solution, but two-pointer and prefix/suffix max methods also exist.
// - The approach is intuitive for visualizing valleys and boundaries in the histogram.
