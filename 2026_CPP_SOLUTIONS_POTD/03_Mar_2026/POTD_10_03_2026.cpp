// Subarrays with First Element Minimum

/*
 *    1. We need to count subarrays where the first element is the minimum.
 *    2. For each element, find the next smaller element to its right.
 *    3. Use a monotonic stack to efficiently compute next smaller indices.
 *    4. If no smaller element exists, assume boundary at array end.
 *    5. Contribution of each element = distance to next smaller index.
 *    6. Sum contributions across all elements to get the answer.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> nextSmaller(n, n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if(!st.empty()) nextSmaller[i] = st.top();
            st.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (nextSmaller[i] - i);
        }
        return ans;
    }
};

// Key Points
// 1. Problem focuses on subarrays with first element as minimum.
// 2. Next smaller element helps define subarray boundaries.
// 3. Monotonic stack ensures efficient computation.
// 4. Each element contributes based on its valid subarray span.
// 5. If no smaller element exists, boundary is array end.
// 6. Summation of contributions gives total count.
// 7. Achieves O(n) time and space efficiency.
