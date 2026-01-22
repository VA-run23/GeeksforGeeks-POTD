/*
    1. The algorithm computes the sum of subarray ranges (max - min for each subarray) using monotonic stacks.
    2. First loop builds a decreasing stack (stMax) to calculate each element’s contribution as maximum in subarrays.
    3. Second loop builds an increasing stack (stMin) to calculate each element’s contribution as minimum in subarrays.
    4. For each popped element, 'left' counts subarrays extending leftwards until a greater/smaller element, 'right' counts rightwards.
    5. Contribution formula: arr[idx] * left * right ensures each element’s role as max/min is counted exactly once.
    6. At the end, result = maxContri - minContri, which equals sum of all subarray ranges.
    7. Time Complexity: O(n) since each element is pushed/popped once; Space Complexity: O(n) for stacks.
*/

// Key Points Recap
// First loop → monotonic decreasing stack → elements as maximums.
// Second loop → monotonic increasing stack → elements as minimums.
// Sentinel values (INT_MAX, INT_MIN) ensure stacks are flushed at the end.
// Formula arr[idx] * left * right counts how many subarrays an element dominates as max/min.
// Final difference gives the desired sum of subarray ranges efficiently.

class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        // code here
        int n = arr.size();
        int maxContri = 0, minContri = 0;


        stack<int> stMax;
        for (int i = 0; i <= n; i++) {
            while (!stMax.empty() && (i == n || arr[stMax.top()] < (i < n ? arr[i] : INT_MAX))) {
                int idx = stMax.top();
                stMax.pop();
                int left = idx - (stMax.empty() ? -1 : stMax.top());
                int right = i - idx;
                maxContri += arr[idx] * left * right;
            }
            stMax.push(i);
        }


        stack<int> stMin;
        for (int i = 0; i <= n; i++) {
            while (!stMin.empty() && (i == n || arr[stMin.top()] > (i < n ? arr[i] : INT_MIN))) {
                int idx = stMin.top();
                stMin.pop();
                int left = idx - (stMin.empty() ? -1 : stMin.top());
                int right = i - idx;
                minContri += arr[idx] * left * right;
            }
            stMin.push(i);
        }

        return maxContri - minContri;
    }
};
