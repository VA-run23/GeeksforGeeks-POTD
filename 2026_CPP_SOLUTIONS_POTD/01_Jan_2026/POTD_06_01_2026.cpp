/*
    1. The function takes an array 'arr' and an integer 'k', aiming to find the maximum XOR of any contiguous subarray of size k.
    2. It initializes 'curr' to store the XOR of the current window and 'mx' to keep track of the maximum XOR found so far.
    3. The first loop computes the XOR of the first k elements to initialize the sliding window.
    4. 'mx' is updated with the maximum between its current value and the initial window XOR.
    5. The second loop slides the window across the array: it removes the XOR contribution of the element leaving the window ('arr[i-k]') and adds the new element ('arr[i]').
    6. After each update, 'mx' is recalculated to ensure it holds the maximum XOR value encountered.
    7. Finally, the function returns 'mx', which is the maximum XOR of any subarray of size k.
       - Time Complexity: O(n), since each element is processed once in the sliding window.
       - Space Complexity: O(1), as only a few variables are used regardless of input size.
*/

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int mx = INT_MIN, curr = 0;
        for(int i = 0; i<k; i++){
            curr ^= arr[i];
        }
        mx = max(mx, curr);
        for(int i = k; i<n; i++){
            curr ^= arr[i-k];
            curr ^= arr[i];
            mx = max(mx, curr);
        }
        return mx;
    }
};