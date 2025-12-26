/*
   1. The function finds the k-th missing positive integer from a sorted array of distinct positive numbers.
   2. Variable 'm' tracks the current candidate number starting from 1, while 'n' stores the array size.
   3. If the array is empty, the k-th missing number is simply 'k' (since all numbers are missing).
   4. For each element in the array, the loop checks numbers smaller than arr[i] (using while m < arr[i]) and decrements k for each missing number.
   5. When k becomes 0, the current number 'm' is returned as the k-th missing number.
   6. After processing each array element, 'm' is updated to arr[i] + 1 to skip over present numbers.
   7. If k is still positive after the loop, the answer lies beyond the last array element, so return m + k - 1.
      Time Complexity: O(n + k) in worst case (linear scan and missing count).
      Space Complexity: O(1) since only constant extra variables are used.
*/

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int m = 1;
        int n = arr.size();
        if (n == 0) return k;

        for (int i = 0; i < n; i++) {
            while (m < arr[i]) { 
                k--;
                if (k == 0) return m;
                m++;
            }
            m = arr[i] + 1; 
        }
        return m + k - 1;  
    }
};