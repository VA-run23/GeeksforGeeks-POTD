/* 
    This function finds the bitonic point (maximum element) in a given array using Binary Search.
    It initializes two pointers, left and right, to the start and end of the array.
    It repeatedly checks the middle element, moving left or right based on whether the sequence is increasing or decreasing.
    If the middle element is greater than its neighbors, it is the maximum and returned.
    Otherwise, if mid is in the increasing part, search moves to the right half, else to the left half.
    Time Complexity: O(log N), since binary search reduces search space exponentially.
    Space Complexity: O(1), as no extra space is used apart from variables.
*/
        

class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int left = 0, right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if ((mid == 0 || arr[mid] > arr[mid - 1]) && (mid == arr.size() - 1 || arr[mid] > arr[mid + 1])) {
                return arr[mid];
            } else if (mid > 0 && arr[mid] > arr[mid - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};

