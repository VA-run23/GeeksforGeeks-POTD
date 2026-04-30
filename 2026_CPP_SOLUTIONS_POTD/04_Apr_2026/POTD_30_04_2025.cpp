// Check if an Array is Max Heap

/*
 *    1. The problem requires verifying if a given array represents a max heap.
 *    2. In a max heap, every parent node must be greater than or equal to its children.
 *    3. The array representation uses indices: left child at 2*i+1, right child at 2*i+2.
 *    4. Only non-leaf nodes need to be checked, i.e., indices up to (n-2)/2.
 *    5. Each parent is compared with its children if they exist within bounds.
 *    6. If any parent is smaller than a child, the array is not a max heap.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        int n = arr.size();
        for(int i = 0; i <= (n-2)/2; i++) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            if(left < n && arr[i] < arr[left]) return false;
            if(right < n && arr[i] < arr[right]) return false;
        }
        return true;
    }
};

// Key Points
// 1. Max heap requires parent >= children.
// 2. Array-based heap uses index math for children.
// 3. Only non-leaf nodes need checking.
// 4. Left child index = 2*i+1.
// 5. Right child index = 2*i+2.
// 6. Bounds must be checked before accessing children.
// 7. Efficient solution runs in O(n) time and O(1) space.