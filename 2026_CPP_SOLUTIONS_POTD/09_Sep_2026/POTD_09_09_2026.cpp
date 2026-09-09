// Max Digit Sum Number in 1 to n

/*
 *    1. The problem asks to find the number ≤ n that has the maximum digit sum.
 *    2. Start with n itself as the initial candidate.
 *    3. Compute digit sum of n and store as bestSum, bestNum = n.
 *    4. For each digit position i:
 *       - If s[i] > '0', reduce it by 1 and set all following digits to '9'.
 *       - This creates a candidate number ≤ n with potentially larger digit sum.
 *    5. Compute digit sum of candidate and compare with bestSum.
 *    6. Update bestNum if candidate has higher digit sum or equal sum but larger value.
 *    7. Return bestNum as the answer.
 */

class Solution {
  public:
    int findMax(int n) {
        string s = to_string(n);
        int len = s.length();

        int bestNum = n;
        int bestSum = 0;
        for (char c : s) bestSum += (c - '0');

        for (int i = 0; i < len; i++) {
            if (s[i] == '0') continue;

            string cand = s;
            cand[i] = (char)(cand[i] - 1);
            for (int j = i + 1; j < len; j++) {
                cand[j] = '9';
            }

            int num = stoi(cand);

            int sum = 0, temp = num;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            if (sum > bestSum || (sum == bestSum && num > bestNum)) {
                bestSum = sum;
                bestNum = num;
            }
        }

        return bestNum;
    }
};

// Key Points
// 1. Candidate numbers formed by reducing one digit and setting later digits to 9.
// 2. Ensures candidate ≤ n.
// 3. Digit sum computed for each candidate.
// 4. Track bestSum and bestNum across all candidates.
// 5. Update when higher digit sum found.
// 6. Tie-breaker: choose larger number if sums equal.
// 7. Runs in O(len) time with O(len) space.