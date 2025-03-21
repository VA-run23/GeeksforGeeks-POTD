/*
1. The function `findMaxSum` calculates the maximum sum of non-adjacent elements in the array `arr`.
2. If the array is empty, the function returns 0; if it contains only one element, it returns that element.
3. Two variables, `prev2` and `prev1`, are used to store the maximum sums for subproblems: 
   sums up to two steps and one step behind the current element.
4. The loop iterates through the array, calculating two options: 
   `take` (including the current element) and `skip` (excluding it).
5. The maximum of these two options (`curr`) becomes the new sum for the current element.
6. The previous sums are updated (`prev2 = prev1` and `prev1 = curr`) for the next iteration.
7. After the loop, `prev1` contains the result, which is the maximum sum of non-adjacent elements.
*/

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0]; 
    
        int prev2 = 0; 
        int prev1 = arr[0]; 
    
        for (int i = 1; i < n; i++) {
            int take = arr[i] + prev2; 
            int skip = prev1;         
            int curr = max(take, skip); 
            prev2 = prev1;        
            prev1 = curr;
        }
    
        return prev1; 
        
    }
};