/* 
    1. This algorithm implements a modified binary search on an almost sorted array.
    2. It checks the mid element as well as its adjacent elements (mid-1 and mid+1) to find the target.
    3. If target matches any of these, it returns the corresponding index.
    4. If target is smaller than arr[mid], search moves left by setting high = mid - 2.
    5. If target is larger than arr[mid], search moves right by setting low = mid + 2.
    6. The approach maintains O(log N) time complexity, making it efficient for large inputs.
    7. Space complexity is O(1) as the algorithm uses only a few extra variables.
        
    //   Linear search also works because it checks each element one by one. 
    //   If the target exists, it will eventually find it. 
    //   However, linear search takes O(N) time in the worst case, 
    //   while binary search reduces search space exponentially, achieving O(log N) complexity.
    //    This makes binary search far more efficient for large arrays.
    
*/


// User function Template for C++
class Solution {
    public:
      int findTarget(vector<int>& arr, int target) {
          // code here
          int n = arr.size();
          int low = 0, high = n - 1;
          
          while (low <= high) {
              int mid = low + (high - low) / 2;
      
              if (arr[mid] == target) return mid;
              if (mid > low && arr[mid - 1] == target) return mid - 1;
              if (mid < high && arr[mid + 1] == target) return mid + 1;
      
              if (arr[mid] > target) {
                  high = mid - 2; 
              } 
  
              else {
                  low = mid + 2;  
              }
          }
          
          return -1; 
    }
};