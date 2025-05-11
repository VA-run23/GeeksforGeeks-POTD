/* 
    1. Use a min heap (priority queue) to maintain the k largest subarray sums.
    2. Iterate through all possible contiguous subarrays and compute their sums.
    3. For each subarray, add the sum to the heap if it has fewer than k elements.
    4. If the heap already contains k elements, compare the new sum with the smallest.
    5. If the new sum is larger, remove the smallest element and insert the new sum.
    6. This ensures the heap always contains the k largest sums seen so far.
    7. The k-th largest sum will be at the top of the heap at the end.
    
    Time Complexity: O(n^2 * log k) -> O(n^2) subarrays, each heap operation takes O(log k).
    Space Complexity: O(k) -> The heap stores only k elements at a time.
*/

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here

        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (minHeap.size() < k) {
                    minHeap.push(sum);
                } else if (sum > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
        
        return minHeap.top();
    }
};