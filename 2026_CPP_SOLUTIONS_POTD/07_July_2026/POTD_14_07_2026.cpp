// Smallest Non-Zero Number

/*
 *    1. The problem asks to find the smallest non-zero number that can be formed from the given array.
 *    2. Start from the last element and work backwards to simulate the construction process.
 *    3. Maintain a running variable x that represents the current reduced value.
 *    4. At each step, update x as (x + arr[i] + 1) / 2 to ensure integer rounding.
 *    5. This backward iteration ensures the smallest possible non-zero number is derived.
 *    6. After processing all elements, check if x equals 0.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
        int x = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            x = (x + arr[i] + 1) / 2;
        }
        
        return (x == 0) ? 1 : x;
    }
};

// Key Points
// 1. Iterate from the end of the array to the beginning.
// 2. Use integer division to maintain smallest possible values.
// 3. Formula ensures rounding up when needed.
// 4. If final result is 0, return 1 as smallest non-zero number.
// 5. No extra data structures are required.
// 6. Efficient linear-time solution.
// 7. Handles edge cases like empty or all-zero arrays.