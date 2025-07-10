/*
    1. The function finds, for each element in the array, the next element to its right with a higher frequency count.
    2. It first constructs a frequency map 'freq' storing how often each number appears in 'arr'.
    3. 'res' is initialized with -1s to hold the result, and 's' is a stack used to track indices awaiting their next greater frequency element.
    4. As we iterate through the array, for each 'i', we check if 'arr[i]' has a higher frequency than the element at the index on the stack top.
    5. If true, 'arr[i]' is the answer for that index; we update 'res' accordingly and pop from the stack.
    6. We then push the current index 'i' onto the stack to potentially resolve later as we progress.
    7. Time Complexity: O(n), each element is pushed/popped at most once; Space Complexity: O(n), for frequency map, result array, and stack.
*/


class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int n = arr.size();
        map<int, int> freq;

        for (auto it : arr) {
            freq[it]++;
        }
        vector<int> res(n, -1);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && freq[arr[i]] > freq[arr[s.top()]]) {
                res[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};

