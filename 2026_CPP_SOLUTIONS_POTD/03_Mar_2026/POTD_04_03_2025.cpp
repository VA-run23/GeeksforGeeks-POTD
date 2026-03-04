/*
    1. This function computes the maximum XOR value among all subarrays of size k.
    2. It first calculates the XOR of the initial k elements and stores it in 'curr'.
    3. The result 'ans' is initialized with this first subarray XOR.
    4. Then, using a sliding window approach, it moves across the array.
    5. For each step, it removes the XOR contribution of the element leaving the window and adds the new element.
    6. At each step, it updates 'ans' with the maximum XOR found so far.
    7. Time Complexity: O(n), Space Complexity: O(1).
*/
class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        int curr = 0,ans = 0, n = arr.size();
        
        for(int i = 0; i<k; i++){
            curr ^= arr[i];
        }
        ans =max(ans,curr);
        
        for(int i = k ; i<n; i++){
            curr ^= arr[i-k];
            curr ^= arr[i];
            ans = max(ans, curr);
        }
        return ans;
    }
};

// Key points:
// - The code uses XOR properties with a sliding window of size k.
// - Initial XOR is computed for the first k elements.
// - Each subsequent window is updated by removing the leftmost element and adding the new one.
// - This avoids recomputing XOR from scratch, making it efficient.
// - The maximum XOR across all windows is tracked and returned.
// - Time complexity is linear, space complexity is constant.
// - This is a straightforward and efficient solution for fixed-size subarray XOR problems.
