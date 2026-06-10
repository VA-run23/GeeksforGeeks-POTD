// Binary Searchable Elements in Array

/*
 *    1. The problem is to count how many elements in an array are searchable using binary search.
 *    2. Binary search requires the array to be sorted, but here we check each element individually.
 *    3. The helper function `check` performs a standard binary search for a given key.
 *    4. The main function iterates through all elements and counts those found by binary search.
 *    5. Since the array is not necessarily sorted, the binary search may not behave correctly.
 *    6. This approach redundantly searches for each element in the array.
 *    7. Time Complexity: O(n log n), Space Complexity: O(1).
 */

class Solution {
public:
    bool check(int key, vector<int>& arr, int n) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] == key)
                return true;
            if (arr[mid] < key)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
    int binarySearchable(vector<int>& arr) {
        // code here
        int n = arr.size(), cnt = 0;
        for (int i : arr) {
            if (check(i, arr, n))
                cnt++;
        }
        return cnt;
    }
};

// Key Points
// 1. Binary search works only on sorted arrays.
// 2. The current implementation assumes the array is sorted.
// 3. Each element is checked individually using binary search.
// 4. This leads to redundant searches since all elements are already present.
// 5. The count will always equal the array size if sorted.
// 6. If unsorted, the binary search may fail for valid elements.
// 7. Optimization is possible by preprocessing min/max arrays instead of repeated searches.