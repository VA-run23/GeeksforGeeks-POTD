/*
    1. We initialize 'toRemove' as k (number of characters to remove) and an empty string 'res' to build our answer.
    2. We iterate through each character 'c' in the input string 's'.
    3. While the last character in 'res' is smaller than 'c', and we still have removals left, we pop it from 'res'.
    4. This greedily removes smaller characters to make room for bigger ones, building a lexicographically larger result.
    5. Each character 'c' is then added to 'res', ensuring relative order is preserved.
    6. After the loop, 'res' might be too long, so we resize it to 'n - k', keeping only the necessary characters.
    7. We return 'res', which now contains the largest possible string in lexicographic order after k deletions.

    Time Complexity: O(n) — each character is pushed and popped at most once.
    Space Complexity: O(n) — to store the result string.
*/

class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n = s.length(), toRemove = k;
        string res;
        for (char c : s) {
            while (!res.empty() && toRemove && res.back() < c) {
                res.pop_back();
                toRemove--;
            }
            res += c;
        }
        res.resize(n - k);
        return res;
    }
};