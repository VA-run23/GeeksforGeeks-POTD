/*
This function calculates the maximums for every subarray of length k.
It uses a queue to handle sliding windows.
It recomputes the maximum value when necessary.
By updating the max value appropriately, it maintains efficiency.
*/
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> ans;
        int n = arr.size();
        queue<int> q;
        
        // First window
        int maxVal = INT_MIN;
        for (int i = 0; i < k; i++) {
            q.push(arr[i]);
            maxVal = max(maxVal, arr[i]);
        }
        ans.push_back(maxVal);
        
        // Sliding window
        for (int i = k; i < n; i++) {
            int removed = q.front();
            q.pop();
            q.push(arr[i]);

            // If the removed element was the max, recompute the max
            if (removed == maxVal) {
                maxVal = INT_MIN;
                queue<int> temp = q; // Copy queue to find new max
                while (!temp.empty()) {
                    maxVal = max(maxVal, temp.front());
                    temp.pop();
                }
            } else {
                // if the removed element is not the maxVal then just compare the new element with maxVal 
                //and then push the new maxVal to the ans vector
                maxVal = max(maxVal, arr[i]);
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};