/*
    1. Base case: If n == 1, return "1" as the first row of the sequence.
    2. Recursively obtain the previous sequence by calling countAndSay(n - 1).
    3. Initialize an empty string ans to store the new sequence.
    4. Traverse prev, counting consecutive occurrences of the same digit.
    5. When a different digit appears, append the count and digit to ans.
    6. Reset count and continue processing the remaining digits.
    7. Time Complexity: O(2^n) due to recursion; Space Complexity: O(2^n) due to recursive calls and string storage.
*/


class Solution {
  public:
    string countAndSay(int n) {
        // code here
        if (n == 1) return "1";

        string prev = countAndSay(n - 1);
        string ans = "";
        
        int count = 1;
        for (int i = 0; i < prev.size(); i++) {
            if (i + 1 < prev.size() && prev[i] == prev[i + 1]) {
                count++;
            } else {
                ans += to_string(count) + prev[i];
                count = 1;
            }
        }
        return ans;
    }
};