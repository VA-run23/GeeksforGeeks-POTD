/*
    1. The goal is to split the array into 'k' or fewer contiguous subarrays such that the largest sum among them is minimized.
    2. The 'isPossible' function checks if we can split the array into ≤ k subarrays with each subarray sum ≤ m.
    3. It iteratively adds elements; if the running sum exceeds m, it starts a new subarray and increments the count.
    4. If at any point count exceeds k or an element is greater than m itself, it returns false.
    5. The 'splitArray' function uses binary search on the range [min(arr), sum(arr)] to find this minimal maximum sum.
    6. On each iteration, it checks mid-point 'm' using 'isPossible'; if valid, it updates answer and narrows the range.
    7. Eventually, the smallest such maximum subarray sum is returned as 'ans'.

    Time Complexity: O(N log S), where N = size of arr, S = sum(arr) − min(arr)
    Space Complexity: O(1) auxiliary
*/

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, int m){
        int count = 1;
        int sum = 0;
        for(auto z : arr){
            sum += z;
            
            if(sum > m){
                count++;
                if(count>k || z>m)
                    return false;
                sum = z;    
            }
            
            
        }
        return true;
    }
  
  
    int splitArray(vector<int>& arr, int k) {
        // code here
        int mini = INT_MAX;
        int sum = 0;
        for(auto z : arr){
            mini = min(mini, z);
            sum += z;
        }
        
        
        int l = mini;
        int r = sum;
        int ans = 0;
        
        while(l<=r){
            int m = l + (r-l)/2;
            if(isPossible(arr, k, m)){
                ans = m;
                r = m-1;
            }
            else
                l = m+1;
            
        }
        return ans;
    }
};