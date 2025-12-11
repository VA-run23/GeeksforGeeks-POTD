/*
   1. The function reconstructs the original array from its pair-sum array (arr), 
      where arr contains sums of all pairs of elements in a fixed order.
   2. First, it calculates the size of the original array (n) using the formula 
      n = sqrt(2 * m) + 1, where m = arr.size(), since m = n*(n-1)/2.
   3. A result vector 'res' of size n is initialized to store the reconstructed array.
   4. The first element res[0] is derived using the formula:
      res[0] = (arr[0] + arr[1] - arr[n-1]) / 2,
      which comes from solving equations of pair sums (a0+a1, a0+a2, a1+a2).
   5. Once res[0] is known, every other element res[i] is computed as:
      res[i] = arr[i-1] - res[0], using the first block of pair sums.
   6. The loop runs from i=1 to n-1, filling the rest of the array efficiently.
   7. Finally, the reconstructed array 'res' is returned as the output.
*/

// Time Complexity: O(n) → single loop to fill the array.
// Space Complexity: O(n) → result vector of size n.

class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        // code here
        int n = (int)(sqrt(arr.size()*2)) + 1;
        vector<int> res(n);
        res[0] = (arr[0] + arr[1] - arr[n-1]) / 2;
        for(int i=1;i<n;i++)res[i] = arr[i-1] - res[0];
        return res;
    }
};