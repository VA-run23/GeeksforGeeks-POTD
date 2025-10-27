/*
    1. This function finds the k pairs with the smallest sums from two sorted arrays arr1 and arr2.
    2. It uses a min-heap (priority_queue with greater<>) to always extract the next smallest sum efficiently.
    3. Initially, it pushes pairs formed by arr1[i] and arr2[0] for the first k elements of arr1 into the heap.
    4. Each heap entry is a tuple: (sum, i, j), where i and j are indices in arr1 and arr2 respectively.
    5. In each iteration, the smallest sum pair is popped and added to the result; then the next pair (i, j+1) is pushed if valid.
    6. This ensures we explore pairs in increasing order of sum without generating all combinations.
    7. Time Complexity: O(k log k), Space Complexity: O(k) — since at most k elements are in the heap and result.
*/

class Solution {
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // code here
        vector<vector<int>> result;
        if (arr1.empty() || arr2.empty() || k == 0) return result;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;

        for (int i = 0; i < arr1.size() && i < k; ++i) {
            minHeap.emplace(arr1[i] + arr2[0], i, 0);
        }

        while (!minHeap.empty() && result.size() < k) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({arr1[i], arr2[j]});

            if (j + 1 < arr2.size()) {
                minHeap.emplace(arr1[i] + arr2[j + 1], i, j + 1);
            }
        }

        return result;
    }
};
