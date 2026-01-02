/*
1. This code solves the "Sort 0s, 1s, and 2s" problem using the Dutch National Flag algorithm.
2. Three pointers are used: 'low' for 0s, 'mid' for current element, and 'high' for 2s.
3. If arr[mid] == 0, it swaps with arr[low] and moves both 'low' and 'mid' forward.
4. If arr[mid] == 1, only 'mid' is incremented since 1s are already in the middle.
5. If arr[mid] == 2, it swaps with arr[high' and decreases 'high' (without incrementing 'mid').
6. This ensures all 0s are moved to the front, 1s stay in the middle, and 2s go to the end.
7. Time Complexity: O(n) (single traversal), Space Complexity: O(1) (constant extra space).
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