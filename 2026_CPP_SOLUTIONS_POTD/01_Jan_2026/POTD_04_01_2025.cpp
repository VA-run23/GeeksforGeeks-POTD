/*
    1. This code solves the "Sort 0s, 1s, and 2s" problem using the Dutch National Flag algorithm.  
    2. Three pointers are used: 'low' (tracks boundary for 0s), 'mid' (current element), and 'high' (boundary for 2s).  
    3. If the current element 'arr[mid]' is 0, it is swapped with 'arr[low]', and both 'low' and 'mid' are incremented.  
    4. If 'arr[mid]' is 1, it is already in the correct place, so only 'mid' is incremented.  
    5. If 'arr[mid]' is 2, it is swapped with 'arr[high]', and 'high' is decremented (without incrementing 'mid' immediately).  
    6. This ensures all 0s move to the left, 1s stay in the middle, and 2s move to the right in a single pass.  
    7. Time Complexity: O(n) (single traversal of array), Space Complexity: O(1) (constant extra space).  
*/

class Solution {
  public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
  
    void sort012(vector<int>& arr) {
        // code here
        int low = 0, mid = 0;
        int high = arr.size() - 1;

        while(mid <= high) {
            if(arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if(arr[mid] == 1) {
                mid++;
            } else { 
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};