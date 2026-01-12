/*
    1. The function computes the maximum of every contiguous subarray of size k using a deque.
    2. The deque stores indices of useful elements in decreasing order of their values (front holds max).
    3. At each iteration, indices that fall out of the current window (i - k) are removed from the front.
    4. Then, smaller elements at the back are popped since they cannot be maximum if a larger element arrives.
    5. The current index is pushed into the deque, ensuring it always holds potential maximum candidates.
    6. Once the window size reaches k (i >= k-1), the element at dq.front() is the maximum for that window.
    7. Time Complexity: O(n) since each element is pushed/popped at most once; Space Complexity: O(k) for deque.
*/

// Key Points:
// - Efficient sliding window maximum using deque (double-ended queue).
// - Avoids recomputation by discarding useless elements.
// - Guarantees linear time performance compared to naive O(n*k).


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