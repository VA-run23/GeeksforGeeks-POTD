// Smallest Substring Containing 0, 1, and 2

/*
 *    1. We need to find the smallest substring that contains all three characters: '0', '1', and '2'.
 *    2. Track the last seen indices of '0', '1', and '2' as we iterate through the string.
 *    3. At each step, check if all three characters have been seen at least once.
 *    4. If yes, compute the current substring length using max(last indices) - min(last indices) + 1.
 *    5. Keep updating the minimum length found so far.
 *    6. If no valid substring exists, return -1.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int smallestSubstring(string s) {
        // code here
        int prev0 = INT_MAX, prev1 = INT_MAX, prev2 = INT_MAX, ans = INT_MAX;
        int n = s.size();
        if(n <3) return -1;
        for(int i = 0; i<n; i++){
            if(s[i]== '0')prev0 = i;
            else if(s[i]== '1')prev1 = i;
            else if(s[i] == '2')prev2 = i;
            if (prev0 != INT_MAX && prev1 != INT_MAX && prev2 != INT_MAX) {
                ans = min(ans, 1 + max(prev0, max(prev1, prev2)) - 
                               min(prev0, min(prev1, prev2)));
            }
        }
        return ans<1e5+3?ans:-1;
    }
};

// Key Points
// 1. Initialize ans with INT_MAX, not 0.
// 2. Track last seen indices of '0', '1', and '2'.
// 3. Only update ans when all three characters have been seen.
// 4. Use max() and min() to calculate substring boundaries.
// 5. Add +1 to account for inclusive length.
// 6. Return -1 if ans was never updated (no valid substring).
// 7. Efficient O(n) solution with constant space.