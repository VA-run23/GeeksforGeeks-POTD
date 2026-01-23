/*
1. The function computes the maximum number of people visible in a line, given their heights in array `arr`.
2. Arrays `left` and `right` store the nearest taller person’s index to the left and right of each position.
3. The first loop uses a monotonic stack to find the nearest taller person on the left for each index.
4. The second loop (right-to-left) uses another monotonic stack to find the nearest taller person on the right.
5. For each person, the visible segment length is calculated as (right[i] - left[i] - 1).
6. The maximum of these segment lengths across all indices is stored in `maxVis`.
7. Time Complexity: O(n) since each element is pushed/popped at most once; Space Complexity: O(n) for stacks and arrays.
*/

class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                left[i] = s.top();
            }
            s.push(i);
        }

        while (!s.empty()) s.pop();


        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                right[i] = s.top();
            }
            s.push(i);
        }

        int maxVis = 0;
        for (int i = 0; i < n; i++) {
            
            maxVis = max(maxVis, right[i] - left[i] - 1);
        }

        return maxVis;
    }
};