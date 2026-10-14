// Roll Characters of String

/*
 *    1. The problem asks to perform multiple roll operations on a string.
 *    2. Each roll[i] means increment the first roll[i] characters by 1 cyclically ('z' → 'a').
 *    3. Instead of updating characters for every roll operation, use a difference array.
 *    4. For each roll value i:
 *       - Increment diff[0].
 *       - Decrement diff[i].
 *    5. Compute prefix sums on diff to determine total shifts applied to each character.
 *    6. Shift each character by diff[i] positions modulo 26.
 *    7. Time Complexity: O(n + m), Space Complexity: O(n).
 */

class Solution {
  public:
    string findRollOut(string& s, vector<int>& roll) {
        // code here
        int n = s.length();
        vector<int> diff(n + 1, 0);

        for (int i : roll) {
            diff[0]++;
            diff[i]--;
        }

        for (int i = 1; i <= n; i++) {
            diff[i] += diff[i - 1];
        }

        string ans;

        for (int i = 0; i < n; i++) {
            char ch = (((s[i] - 'a') + diff[i]) % 26) + 'a';
            ans += ch;
        }

        return ans;
    }
};

// Key Points
// 1. Uses difference array to handle multiple range updates efficiently.
// 2. Each roll operation affects prefix [0, roll[i)-1].
// 3. diff[0]++ starts the effect of a roll.
// 4. diff[roll[i]]-- ends the effect of a roll.
// 5. Prefix sum gives total rotations for each position.
// 6. Characters are shifted cyclically using modulo 26.
// 7. Runs in O(n + m) time instead of O(n * m).