// N-Digit Numbers with Increasing Digits

/*
 *    1. The problem requires generating all n-digit numbers with digits in strictly increasing order.
 *    2. Digits must be chosen from 0–9, ensuring no repetition and increasing sequence.
 *    3. A recursive backtracking approach is used to build numbers digit by digit.
 *    4. At each step, the next digit must be greater than the previous one to maintain increasing order.
 *    5. Base case occurs when n digits are chosen, then the number is added to the result.
 *    6. Special handling is done for n=1 to include 0 as a valid number.
 *    7. Time Complexity: O(C(10, n)) since combinations are generated; Space Complexity: O(C(10, n)) for storing results.
 */

class Solution {
    public:
    void solve(int n, vector<int> &res, int num, int start) {
        if (n == 0) {
            res.push_back(num);
            return;
        }
        for (int i = start ; i <= 9 ; i++) {
            num = num*10 + i;
            solve(n - 1, res, num, i + 1);
            num = num/10;
        }
    }
    vector<int> increasingNumbers(int n) {
        // code here
        vector<int> res;
        solve(n, res, 0, 1);
        if (n == 1)
            res.insert(res.begin(), 0);
        return res;
    }
};

// Key Points
// 1. Uses recursion with backtracking to generate numbers.
// 2. Ensures digits are strictly increasing by controlling the start index.
// 3. Handles edge case for single-digit numbers by including 0.
// 4. Builds numbers digit by digit using multiplication and division.
// 5. Avoids repetition of digits by incrementing the start index.
// 6. Efficiently generates only valid increasing numbers without brute force.
// 7. Complexity depends on binomial coefficient C(10, n).w