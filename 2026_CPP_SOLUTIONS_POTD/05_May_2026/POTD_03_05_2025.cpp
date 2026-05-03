// Sort by Set Bit Count

/*
 *    1. The problem requires sorting integers based on the number of set bits in their binary representation.
 *    2. A stable sort is necessary to preserve the relative order of elements with equal set bit counts.
 *    3. The built-in function __builtin_popcount efficiently counts set bits in an integer.
 *    4. The comparator ensures elements with higher set bit counts come first.
 *    5. Stable_sort is used instead of sort to maintain order among equal set bit counts.
 *    6. The function returns the modified array after sorting.
 *    7. Time Complexity: O(n log n), Space Complexity: O(1) auxiliary.
 */

class Solution {
  public:
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        stable_sort(arr.begin(), arr.end(), [](int x, int y){return __builtin_popcount(x) > __builtin_popcount(y);});
        return arr;
    }
};

// Key Points
// 1. Sorting is based on set bit count, not numerical value.
// 2. Stable sort preserves relative order of equal set bit counts.
// 3. __builtin_popcount is an efficient built-in function.
// 4. Comparator ensures descending order of set bit counts.
// 5. Time complexity is O(n log n).
// 6. Space complexity is O(1) auxiliary.
// 7. Useful in problems involving bit manipulation and ordering.