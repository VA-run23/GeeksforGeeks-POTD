// Numbers Without d as Digit

/*
 *    1. The problem asks to count how many numbers ≤ n do not contain digit d.
 *    2. Convert n into its digit array for digit DP processing.
 *    3. Use recursion with memoization: f(i, tight, started, m, d, digits, dp).
 *    4. Parameters:
 *       - i → current index in digits
 *       - tight → whether current prefix matches n exactly
 *       - started → whether a non-zero digit has been placed
 *    5. At each position, try digits 0–9, skipping digit d and respecting tight bounds.
 *    6. Accumulate counts recursively, storing results in dp[i][tight][started].
 *    7. Time Complexity: O(m * 2 * 2 * 10) = O(m), Space Complexity: O(m).
 */

class Solution {
    int f(int i, int t, int c, int m, int &d, vector<int> &digits, vector<vector<vector<int>>> &dp) {
        if (i == m) return c;
        if (dp[i][t][c] != -1) return dp[i][t][c];
        int ans = 0;
        for (int k = 0; k < 10; k++) {
            if ((k != 0 || c != 0) && ((k == d) || (t == 0 && k > digits[i]))) continue;
            ans += f(i + 1, t | (k < digits[i]), c | (k != 0), m, d, digits, dp);
        }
        return dp[i][t][c] = ans;
    }
  public:
    int countWithout(int &n, int &d) {
        // code here
        vector<int> digits;
        for (int i = n; i > 0; i /= 10) digits.push_back(i % 10);
        vector<vector<vector<int>>> dp(digits.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        reverse(digits.begin(), digits.end());
        int ans = f(0, 0, 0, digits.size(), d, digits, dp);
        return ans;
    }
};

// Key Points
// 1. Digit DP approach to count valid numbers.
// 2. Converts n into digit array for processing.
// 3. Recursion tracks position, tightness, and started flag.
// 4. Skips digit d and respects upper bound constraints.
// 5. Memoization avoids recomputation of states.
// 6. Base case returns 1 when a valid number is formed.
// 7. Runs efficiently in O(m) time with O(m) space.