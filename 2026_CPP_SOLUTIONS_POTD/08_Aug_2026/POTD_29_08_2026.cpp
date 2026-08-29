// Count Subsequences Divisible by n

/*
 *    1. The problem asks to count subsequences of a string s that form numbers divisible by n.
 *    2. Use recursion with memoization (DP) to explore subsequences.
 *    3. State parameters:
 *       - idx → current index in string
 *       - carry → current remainder modulo n
 *    4. Base case: if idx == s.size(), return 1 if carry == 0 else 0.
 *    5. Transition:
 *       - Skip current digit → solve(idx+1, carry)
 *       - Include current digit → new remainder = (carry*10 + digit) % n
 *    6. Store results in DP table vec[carry][idx] to avoid recomputation.
 *    7. Time Complexity: O(n * |s|), Space Complexity: O(n * |s|).
 */

class Solution {
    vector<vector<int>> vec;
    int mod = 1e9 + 7;

    int solve(int idx, string& s, int n, int carry) {
        if (idx >= s.size())
            return carry ? 0 : 1;

        if (vec[carry][idx] != -1)
            return vec[carry][idx];

        // Option 1: skip current digit
        int res = solve(idx + 1, s, n, carry);

        // Option 2: include current digit
        int num = (carry * 10) + (int)(s[idx] - '0');
        res = (res + solve(idx + 1, s, n, num % n)) % mod;

        return vec[carry][idx] = res;
    }

  public:
    int countSubsequences(string& s, int n) {
        vec = vector<vector<int>>(n + 1, vector<int>(s.size() + 1, -1));
        int res = solve(0, s, n, 0);
        return (res - 1 + mod) % mod; // subtract empty subsequence
    }
};

// Key Points
// 1. Recursion explores subsequences with/without current digit.
// 2. Carry tracks remainder modulo n.
// 3. DP memoization avoids recomputation of states.
// 4. Base case ensures divisibility check at end.
// 5. Subtracts empty subsequence from final result.
// 6. Uses modulo 1e9+7 for large counts.
// 7. Runs in O(n * |s|) time with O(n * |s|) space.