/*
1. The function `sortIt` takes a vector of integers and rearranges it so that odd numbers come first (in descending order) and even numbers follow (in ascending order).
2. It initializes `idx = 0` to track the boundary where odd numbers will be placed.
3. In the first loop, whenever an odd number is found, it is swapped with the element at position `idx`, and `idx` is incremented — effectively partitioning odds to the front.
4. After partitioning, the subarray from `arr.begin()` to `arr.begin() + idx` contains all odd numbers.
5. These odd numbers are sorted in descending order using `sort(..., greater<int>())`.
6. The remaining subarray from `arr.begin() + idx` to `arr.end()` contains all even numbers, which are sorted in ascending order by default.
7. Time Complexity: O(n log n) due to sorting; Space Complexity: O(1) (in-place sorting, ignoring recursion stack).
*/

class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        int n = arr.size();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 != 0) {
                swap(arr[i], arr[idx]);
                idx++;
            }
        }
        sort(arr.begin(), arr.begin() + idx, greater<int>());
        sort(arr.begin() + idx, arr.end());
    }
};
