// Subarrays with Sum in Range

/*
 *    1. The problem asks to count subarrays whose sum lies within a given range [l, r].
 *    2. To solve this, first count subarrays with sum ≤ X using a sliding window approach.
 *    3. Maintain a running sum and adjust the left pointer when the sum exceeds X.
 *    4. For each right pointer, add (right - left + 1) to the total, representing valid subarrays ending at right.
 *    5. This gives a helper function countAtMost(arr, X) that counts subarrays with sum ≤ X.
 *    6. The final answer is countAtMost(arr, r) - countAtMost(arr, l - 1), ensuring sums fall in [l, r].
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int countAtMost(vector<int>& arr, int X) {
        int total = 0, currSum = 0;
        int left = 0;
        
        for (int right = 0; right < arr.size(); right++) {
            currSum += arr[right];
            
            while (currSum > X) {
                currSum -= arr[left];
                left++;
            }
            total += (right - left + 1);
        }
        return total;
    }
    
    int countSubarray(vector<int>& arr, int l, int r) {
        // code here
        return (countAtMost(arr, r) - countAtMost(arr, l - 1));
    }
};

// Key Points
// 1. Uses sliding window to count subarrays with sum ≤ X.
// 2. Adjusts left pointer when sum exceeds X.
// 3. Adds (right - left + 1) for each valid window.
// 4. Helper function countAtMost handles upper bound queries.
// 5. Final answer is difference of two counts for [l, r] range.
// 6. Runs in linear time with constant space.
// 7. Efficient and elegant solution for range-based subarray sums.