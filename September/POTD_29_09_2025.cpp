/*
    1. This function finds the maximum sum of any contiguous subarray with length between 'a' and 'b'.
    2. It first builds a prefix sum array to allow constant-time subarray sum calculations.
    3. A deque is used to maintain candidate starting indices for subarrays within the valid length range.
    4. For each end index 'j' from 'a' to 'n', it removes indices from the back of the deque that are worse than the current candidate.
    5. It then adds the new candidate index 'j-a' to the deque and removes any indices from the front that would make the subarray longer than 'b'.
    6. The maximum subarray sum is updated using the difference between the current prefix and the best candidate prefix from the deque.
    7. Time Complexity: O(n), Space Complexity: O(n), due to prefix sum and deque operations being linear.
*/

class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        // code here
        
        int n = arr.size();
        vector<int> prefix(n+1, 0);

        for (int i = 0; i < n; i++) 
            prefix[i+1] = prefix[i] + arr[i];

        deque<int> dq; 
        int ans = INT_MIN;

        for (int j = a; j <= n; j++) {
            while (!dq.empty() && prefix[dq.back()] >= prefix[j-a])
                dq.pop_back();
            dq.push_back(j-a);
            while (!dq.empty() && j - dq.front() > b)
                dq.pop_front();

            ans = max(ans, prefix[j] - prefix[dq.front()]);
        }
        return ans;
    }
};