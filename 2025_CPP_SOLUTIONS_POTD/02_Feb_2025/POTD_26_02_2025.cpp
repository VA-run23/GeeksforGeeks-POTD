class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
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