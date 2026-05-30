// Replace with XOR of Adjacent

/*
 *    1. Given an array, replace each element with XOR of its adjacent elements.
 *    2. For the first element, XOR it with the second element.
 *    3. For the last element, XOR it with the second last element.
 *    4. For all middle elements, XOR of previous and next element is used.
 *    5. Temporary variable stores the previous value to avoid overwriting issues.
 *    6. Iteration ensures each element is updated in place.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
    public:
    void replaceElements(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n == 1)return;
        int temp = 0;
        for (int i = 0; i<n; i++) {
            if (i == 0) {
                temp = arr[i];
                arr[i] = arr[i]^arr[i + 1];
            }
            else if (i == n - 1) {
                arr[i] = arr[i]^temp;
            }
            else {
                int xorVal = temp^arr[i + 1];
                temp = arr[i];
                arr[i] = xorVal;
            }
        }
        return;
    }
};

// Key Points
// 1. First element is XORed with second.
// 2. Last element is XORed with second last.
// 3. Middle elements are XORed with neighbors.
// 4. Temporary variable prevents overwriting.
// 5. In-place transformation is achieved.
// 6. Linear traversal ensures efficiency.
// 7. Optimal with O(n) time and O(1) space.