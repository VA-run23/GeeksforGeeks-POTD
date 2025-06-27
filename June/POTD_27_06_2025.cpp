/* 
    1. This function counts the total number of digit sequences of length 'n' that can be formed on a numeric keypad with knight-like moves.
    2. It uses dynamic programming where dp[i][j] represents the number of sequences of length i ending with digit j.
    3. The 'vec' array maps each digit to the digits reachable from it (including itself) in one move according to keypad movement constraints.
    4. Base case: sequences of length 1 can start from any digit, so dp[1][j] = 1 for all j.
    5. For lengths ≥ 2, dp[i][j] is updated by summing the dp[i-1][prev] for all digits prev that can move to j.
    6. The answer is the total number of sequences of length 'n', which is the sum of all dp[n][j] for j in [0,9].
    7. Time complexity: O(n × 10 × k) where k is max neighbors (≤5); Space complexity: O(n × 10).
*/

class Solution {
  public:
    int getCount(int n) {
          if (n <= 0) return 0;

    long long dp[n + 1][10];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            dp[i][j] = 0;
        }
    }

    vector<vector<int>> vec(10);
    vec[0] = {0, 8};
    vec[1] = {1, 2, 4};
    vec[2] = {1, 2, 3, 5};
    vec[3] = {2, 3, 6};
    vec[4] = {1, 4, 5, 7};
    vec[5] = {2, 4, 5, 6, 8};
    vec[6] = {3, 5, 6, 9};
    vec[7] = {4, 7, 8};
    vec[8] = {0, 5, 7, 8, 9};
    vec[9] = {6, 8, 9};

    for (int i = 0; i < 10; ++i) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int prev : vec[j]) {
                dp[i][j] += dp[i - 1][prev];
            }
        }
    }

    long long sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += dp[n][i];
    }

    return sum;
    }
    
};

