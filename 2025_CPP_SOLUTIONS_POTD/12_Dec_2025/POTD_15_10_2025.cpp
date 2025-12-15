/*
    1. First, compute total sums of elements at even and odd indices in the array.
    2. Maintain prefix sums (leftEven, leftOdd) to track contributions before the current index.
    3. For each index i, subtract arr[i] from the appropriate total (evenSum or oddSum) to simulate deletion.
    4. After deletion, elements to the right shift left, so their parity flips (even ↔ odd).
    5. Check if leftEven + remainingOdd equals leftOdd + remainingEven; if true, increment ans.
    6. Update prefix sums by adding arr[i] to leftEven or leftOdd depending on its original parity.
    7. Finally, return ans, which counts indices where deletion balances even and odd sums.
    Time Complexity: O(n) (single pass for totals + single pass for checks).
    Space Complexity: O(1) (only a few integer variables used).
*/

class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n = arr.size();
    
        int evenSum = 0, oddSum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) evenSum += arr[i];
            else oddSum += arr[i];
        }
        
        int ans = 0;
        int leftEven = 0, leftOdd = 0;
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) evenSum -= arr[i];
            else oddSum -= arr[i];
            
            if (leftEven + oddSum == leftOdd + evenSum) {
                ans++;
            }
            
            if (i % 2 == 0) leftEven += arr[i];
            else leftOdd += arr[i];
        }
        
        return ans;
    }
};