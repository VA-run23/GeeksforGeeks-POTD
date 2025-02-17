class Solution {
public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Use a min-heap (priority queue) to store the k largest elements.
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int x : arr) {
            if (minHeap.size() < k) {
                minHeap.push(x);
            } else if (x > minHeap.top()) {
                minHeap.pop();
                minHeap.push(x);
            }
        }

        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        reverse(result.begin(), result.end()); 
        return result;
    }
};