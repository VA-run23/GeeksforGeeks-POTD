/*
1. The function rearranges the array based on the absolute difference of each element from a given number x.
2. It uses 'stable_sort' to ensure that elements with equal differences retain their original relative order.
3. A lambda comparator is defined inline to compare elements by their absolute difference from x.
4. The sorting is done directly on the array without creating auxiliary structures like index maps.
5. This approach is more elegant and memory-efficient than the previous version using pairs.
6. Time Complexity: O(n log n) due to sorting; Space Complexity: O(log n) auxiliary space for merge sort.
7. This satisfies the problem constraint of preserving order for equal differences.
*/

class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x);
        });
    }
};