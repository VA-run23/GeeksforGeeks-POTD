/*
    1. This function finds the maximum element in every contiguous subarray of size k.
    2. It uses a deque to store indices of useful elements in decreasing order of values.
    3. At each step, indices that fall out of the current window (i - k) are removed from the front.
    4. Smaller elements at the back are discarded since they cannot be maximum if a larger element exists later.
    5. The front of the deque always holds the index of the maximum element for the current window.
    6. Once the window size reaches k, the maximum (arr[dq.front()]) is added to the result vector.
    7. Time Complexity: O(n), Space Complexity: O(k) due to the deque.
*/

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> ans;
        deque<int> dq; 

        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};

// Key points:
// - The deque ensures we always have the maximum element at the front.
// - Out-of-window indices are removed to maintain correctness.
// - Smaller elements are discarded to keep only potential maximums.
// - Each element is pushed and popped at most once, giving O(n) efficiency.
// - The result vector stores maximums for each valid window.
// - This is the standard sliding window maximum approach using deque.
// - Optimal balance of speed and memory compared to naive O(n*k) methods.