/*
    1. This function solves the Chocolate Distribution Problem: 
    given packets of chocolates, distribute them to minimize the difference 
    between the maximum and minimum chocolates received.
    2. It first checks if the array is empty or has fewer elements than required (m).
    3. The array is sorted so that chocolates are in ascending order.
    4. The logic then slides a window of size m across the sorted array.
    5. For each window, it calculates the difference between the last and first element.
    6. The minimum of all such differences is stored as the answer.
    7. Time Complexity: O(n log n) due to sorting; Space Complexity: O(1) auxiliary space.
*/
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        int n = a.size();
        if(n == 0 || n < m){
            return 0;
        }
        
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        for(int i = 0; i +m -1< n; i++){
            int curr =  a[i + m - 1] -a[i] ;
            ans = min(ans , curr);
        }
        return ans;
    }
};

// Key points:
// - The problem is about minimizing unfairness in distribution.
// - Sorting ensures that the closest values are grouped together.
// - A sliding window of size m captures possible distributions.
// - The difference between first and last in the window gives unfairness.
// - The minimum difference across all windows is the solution.
// - Efficient because sorting + linear scan is optimal.
// - Handles edge cases where array size < m.
