// Maximum Number of People Defeated

/*
 *    1. We need to find the maximum number of people that can be defeated.
 *    2. Each person requires a certain amount of power based on square numbers.
 *    3. The sum of squares up to 'n' is given by n(n+1)(2n+1)/6.
 *    4. We must ensure the total power used does not exceed 'p'.
 *    5. Binary search is applied to find the largest 'n' satisfying the condition.
 *    6. The answer is updated whenever the sum is within the limit.
 *    7. Time Complexity: O(log n), Space Complexity: O(1).
 */

class Solution {
public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int low = 1;
        int high = 1000;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            long long x = (mid * (mid + 1) * (2 * mid + 1)) / 6;
            if (x > p)
                high = mid - 1;
            else {
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
};

// Key Points
// 1. Problem reduces to finding maximum 'n' with sum of squares ≤ p.
// 2. Formula for sum of squares is used directly.
// 3. Binary search ensures efficient solution.
// 4. Upper bound chosen as 1000 (safe for constraints).
// 5. Answer updated when condition is satisfied.
// 6. Works in logarithmic time due to binary search.
// 7. Constant space usage makes it memory efficient.