// Kth Largest in a Stream

/*
 *    1. Maintain a min-heap of size k to track the kth largest element.
 *    2. Push elements into the heap as they arrive in the stream.
 *    3. If heap size exceeds k, pop the smallest element to maintain size.
 *    4. For the first k-1 elements, kth largest does not exist, so return -1.
 *    5. From the kth element onward, the top of the heap gives the kth largest.
 *    6. Store results in a vector to represent kth largest at each step.
 *    7. Time Complexity: O(n log k), Space Complexity: O(k)
 */

class Solution {
public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int> pq;
        vector<int> result;
        for (int i = 0; i < k - 1; i++) {
            pq.push(-arr[i]);
            result.push_back(-1);
        }

        for (int i = k - 1; i < arr.size(); i++) {
            pq.push(-arr[i]);
            if (pq.size() > k) {
                pq.pop();
            }
            result.push_back(-1 * pq.top());
        }
        return result;
    }
};

// Key Points
// 1. Use a min-heap to efficiently track kth largest.
// 2. Negative values simulate min-heap using default max-heap.
// 3. Push each new element into the heap.
// 4. Pop smallest when heap exceeds size k.
// 5. Return -1 for positions where kth largest is undefined.
// 6. Heap top gives kth largest after k elements.
// 7. Efficient for streaming input with O(n log k) complexity.