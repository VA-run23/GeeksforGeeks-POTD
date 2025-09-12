/*
   1. Sort the array to easily access the smallest and largest elements.
   2. Initialize the result as the difference between the max and min heights before any changes.
   3. Set initial bounds: smallest = arr[0] + k, largest = arr[n-1] - k.
   4. Iterate through the array to evaluate new min and max heights after adjusting each element.
   5. Skip iterations where the adjusted height becomes negative.
   6. Update the result with the minimum difference found between maxHeight and minHeight.
   7. Return the smallest possible difference after all valid adjustments.
      Time Complexity: O(n log n) due to sorting; Space Complexity: O(1) as no extra space is used.
*/


class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n == 1) return 0;  
    
        sort(arr.begin(), arr.end());
        int result = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 0; i < n - 1; i++) {
            int minHeight = min(smallest, arr[i + 1] - k);
            int maxHeight = max(largest, arr[i] + k);
            if (minHeight < 0) continue;
            result = min(result, maxHeight - minHeight);
        }

        return result;
    }
};