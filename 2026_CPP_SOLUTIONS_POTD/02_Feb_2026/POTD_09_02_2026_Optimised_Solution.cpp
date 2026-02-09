
/*
    1. This function finds the index of the smallest element in a rotated sorted array.  
    2. The smallest element’s index equals the number of rotations applied to the array.  
    3. It uses binary search to efficiently narrow down the search space.  
    4. If arr[mid] > arr[mid+1], then mid+1 is the rotation point.  
    5. If arr[mid] > arr[hi], the minimum lies in the right half, so move low = mid+1.  
    6. Otherwise, the minimum lies in the left half (including mid), so set hi = mid.  
    7. Time Complexity: O(log n), Space Complexity: O(1).  
*/

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int hi = arr.size() - 1, low = 0;
        while(low < hi){
            int mid = low + (hi - low)/2;
            if(mid  >  0 && arr[mid] > arr[mid  + 1]){
                return mid + 1;
            }else if (arr[mid] > arr[hi]){
                low = mid + 1 ;
                
            }else {
                hi = mid;
            }
        }
        return low;
    }
};

// Key points:
// - The algorithm identifies the smallest element, which marks the rotation count.
// - Binary search is used instead of linear search for efficiency.
// - The check arr[mid] > arr[mid+1] directly finds the pivot if present.
// - Otherwise, comparisons with arr[hi] decide whether to search left or right.
// - Returning 'low' at the end works because low == hi points to the minimum.
// - This approach is optimal with O(log n) time and constant space.
// - It avoids unnecessary scanning of the entire array.