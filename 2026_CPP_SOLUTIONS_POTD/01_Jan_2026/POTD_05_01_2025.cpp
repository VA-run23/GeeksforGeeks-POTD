/*
    1. The function 'maxSubarraySum' calculates the maximum sum of any contiguous subarray of size 'k' using a sliding window technique.  
    2. First, it initializes variables: 'n' for array size, 'ans' as the minimum possible integer, and 'curr' to store the current window sum.  
    3. It computes the sum of the first 'k' elements and assigns it to 'curr', updating 'ans' with this initial sum.  
    4. Then, it iterates from index 'k' to 'n-1', sliding the window forward by subtracting the element leaving the window ('arr[i-k]') and adding the new element ('arr[i]').  
    5. After each slide, it updates 'ans' with the maximum of the current sum and the previously stored maximum.  
    6. Finally, the function returns 'ans', which holds the maximum sum of any subarray of size 'k'.  
    7. Time Complexity: O(n) because each element is processed once. Space Complexity: O(1) since only a few extra variables are used.  
*/

// Key Points:
// - Uses sliding window to avoid recomputing sums from scratch.
// - Efficient compared to brute force (which would be O(nk)).
// - Handles edge cases like k = 1 or k = n seamlessly.
// - Returns the maximum possible sum of any contiguous subarray of size k.

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        int ans = INT_MIN, curr = 0;
        for(int i = 0; i<k; i++){
            curr += arr[i];
        }
        ans = max(ans, curr);
        for(int i = k; i<n; i++){
            curr -= arr[i-k];
            curr += arr[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};