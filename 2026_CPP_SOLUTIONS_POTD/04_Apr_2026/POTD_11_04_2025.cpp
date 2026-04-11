// Count Increasing Subarrays

/*
 *    1. We are asked to count all strictly increasing subarrays in the given array.
 *    2. An increasing subarray is defined as a contiguous sequence where each element is greater than the previous.
 *    3. We iterate through the array while maintaining the length of the current increasing streak.
 *    4. When the streak breaks, we add the number of increasing subarrays formed by that streak using the formula cnt*(cnt-1)/2.
 *    5. Reset the streak counter and continue scanning until the end of the array.
 *    6. Finally, add the contribution of the last streak to the answer.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n= arr.size(), cnt = 1, ans = 0;
        if(n<= 1)return n;
        
        for(int i = 1; i<n; i++){
            if(arr[i] > arr[i-1])cnt++;
            else{
                ans = ans + cnt*(cnt - 1)/2 ;
                cnt = 1;
            }
        }
        ans += (cnt * (cnt - 1)) / 2; 
        return ans;
    }
};

// Key Points
// 1. Increasing subarrays are contiguous and strictly increasing.
// 2. Use a counter to track the length of the current increasing streak.
// 3. Formula cnt*(cnt-1)/2 counts subarrays in a streak of length cnt.
// 4. Reset counter when streak breaks.
// 5. Add contribution of last streak after loop ends.
// 6. Handles edge cases like empty or single-element arrays.
// 7. Efficient O(n) solution with constant space.