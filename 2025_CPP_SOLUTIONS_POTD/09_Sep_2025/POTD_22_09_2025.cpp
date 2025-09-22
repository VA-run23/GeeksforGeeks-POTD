/*
    1. This code computes the maximum of minimums for every window size in the input array 'arr'.
    2. It first finds the previous smaller element ('left') and next smaller element ('right') for each index using monotonic stacks.
    3. These boundaries help determine the maximum window size where each element is the minimum.
    4. For each element, it calculates the window length as 'right[i] - left[i] - 1' and updates the 'answer' array at 'length - 1' with the maximum value.
    5. A second pass from right to left ensures that smaller window sizes inherit the maximums from larger ones.
    6. The final 'answer' array contains the maximum of minimums for all window sizes from 1 to n.
    7. Time Complexity: O(n), Space Complexity: O(n) — due to the use of stacks and auxiliary arrays.
*/

class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> s;


        for (int i = 0; i < n; ++i) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty())
                left[i] = s.top();
            s.push(i);
        }

        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            if (!s.empty())
                right[i] = s.top();
            s.push(i);
        }

        vector<int> answer(n, 0);

        for (int i = 0; i < n; ++i) {
            int length = right[i] - left[i] - 1;
            answer[length - 1] = max(answer[length - 1], arr[i]);
        }

        for (int i = n - 2; i >= 0; --i)
            answer[i] = max(answer[i], answer[i + 1]);

        return answer;
    }
};