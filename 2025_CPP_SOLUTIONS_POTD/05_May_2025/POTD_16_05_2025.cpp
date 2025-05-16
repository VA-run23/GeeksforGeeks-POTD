/*
    1. Initialize a min heap to store tuples (value, row index, column index) and track the maximum value encountered.
    2. Push the first element of each row into the heap and update the maximum value.
    3. Extract the smallest element from the heap and update the range if the current difference is smaller.
    4. If the extracted element is the last in its row, break the loop as we can't form a complete range.
    5. Otherwise, push the next element from the same row into the heap and update the maximum value.
    6. Repeat until we exhaust one of the lists, ensuring the smallest range covering all lists is found.
    7. Time Complexity: O(n log k), where n is the total number of elements and k is the number of lists; Space Complexity: O(k), as we store one element from each list in the heap.
*/


class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
        int k = arr.size(); 
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        int mxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;

        for (int i = 0; i < k; i++) {
            minHeap.push(make_tuple(arr[i][0], i, 0));
            mxVal = max(mxVal, arr[i][0]);
        }

        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int minVal = get<0>(curr);
            int row = get<1>(curr);
            int idx = get<2>(curr);

            if (mxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = mxVal;
            }

            if (idx + 1 == arr[row].size()) break;

            int nextVal = arr[row][idx + 1];
            minHeap.push(make_tuple(nextVal, row, idx + 1));
            mxVal = max(mxVal, nextVal);
        }

        return {rangeStart, rangeEnd};
    }
};