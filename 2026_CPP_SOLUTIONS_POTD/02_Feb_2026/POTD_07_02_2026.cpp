/*
    1. This function computes the maximum sum of i*arr[i] across all rotations of the array.
    2. First, it calculates the total sum of elements (arrSum) and the initial configuration value (currVal).
    3. The initial configuration is the sum of i*arr[i] for the original array.
    4. Then, it iteratively computes the value for each rotation using a recurrence relation.
    5. The recurrence: nextVal = currVal + arrSum - n*arr[n-k], avoids recomputing from scratch.
    6. maxVal keeps track of the maximum value encountered across all rotations.
    7. Time Complexity: O(n), Space Complexity: O(1).
*/

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int arrSum = 0;
        int currVal = 0;

        for (int i = 0; i < n; i++) {
            arrSum += arr[i];
            currVal += i * arr[i];
        }

        int maxVal = currVal;

        for (int k = 1; k < n; k++) {
            currVal = currVal + arrSum - n * arr[n - k];
            maxVal = max(maxVal, currVal);
        }

        return maxVal;
    }
};

// Key points:
// - The problem asks for maximum sum of i*arr[i] over all rotations.
// - Direct brute force would be O(n^2), but recurrence reduces it to O(n).
// - arrSum is reused to avoid recomputation.
// - currVal is updated efficiently using the relation instead of recalculating.
// - maxVal stores the best result across rotations.
// - This is the optimal solution in terms of time and space.
// - The approach leverages mathematical insight rather than brute force.
