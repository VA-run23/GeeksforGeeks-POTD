// Segregate 0s and 1s

/*
 *    1. Method 1 uses accumulate to count the number of 1s in the array.
 *    2. The number of 0s is derived as total size minus the count of 1s.
 *    3. The array is then overwritten: first with 0s, then with 1s.
 *    4. This approach runs in linear time and constant space.
 *    5. Method 2 uses the standard sort function to reorder elements.
 *    6. Sorting ensures all 0s come before 1s, but is less efficient.
 *    7. Method 1: O(n) time, O(1) space; Method 2: O(n log n) time, O(1/log n) space.
 */

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        for(int i = 0; i<n - sum; i++){
            arr[i] = 0;
        }
        for(int i = n - sum; i<n; i++){
            arr[i] = 1;
        }
    }
};

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
    }
};

// Key Points
// 1. Method 1 is optimal when array contains only 0s and 1s.
// 2. Method 2 is more general but slower.
// 3. Method 1 uses counting and overwriting.
// 4. Method 2 leverages built-in sorting.
// 5. Method 1 runs in O(n), Method 2 in O(n log n).
// 6. Both methods are in-place with minimal extra space.
// 7. Method 1 is preferred for binary arrays; Method 2 for mixed arrays.