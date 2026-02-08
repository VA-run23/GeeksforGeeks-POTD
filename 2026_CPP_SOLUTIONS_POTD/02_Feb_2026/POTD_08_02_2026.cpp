/*
1. This function solves the "Maximum Product Subarray" problem.  
2. It keeps track of both minimum and maximum products at each step, since a negative number can flip signs.  
3. Initially, minp and maxp are set to the first element, and ans stores the best product found so far.  
4. For each element, if it’s negative, minp and maxp are swapped to account for sign reversal.  
5. minp is updated as the minimum between the current element and minp*arr[i], while maxp is updated similarly with max.  
6. ans is updated with the maximum value of ans and maxp at each iteration.  
7. Time Complexity: O(n), Space Complexity: O(1).  
*/

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int minp = arr[0], maxp = arr[0];
        int n= arr.size();
        int ans =arr[0];
        for(int i = 1; i<n; i++){
            if(arr[i] < 0){
                swap(minp, maxp);
            }
            minp = min(arr[i], minp * arr[i]);
            maxp = max(arr[i], maxp * arr[i]);
            ans = max(ans, maxp);
        }
        return ans;
    }
};

// Key points:
// - Negative numbers can flip the product, so both min and max are tracked.
// - Swapping minp and maxp when encountering a negative ensures correctness.
// - The algorithm is linear in time and constant in space.
// - ans always stores the best product found so far.
// - This is the standard optimal solution for maximum product subarray.
