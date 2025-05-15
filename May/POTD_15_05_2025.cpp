/*
    1. Initialize a frequency array freq of size 26 to count occurrences of each character in s.
    2. Traverse the string and update the frequency count for each character.
    3. Iterate over the frequency array, calculating valid substrings using the formula: (count * (count + 1)) / 2.
    4. The formula is derived from combinatorial counting of substrings where a given character appears as both the start and end.
    5. This solution runs in O(n) time as we iterate through the string once and process the frequency array in a single pass.
    6. Space complexity is O(1) because the frequency array has a fixed size of 26 (constant space usage).
    7. The approach leverages counting instead of brute-force checking, making it efficient compared to O(n²) solutions.
*/

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        vector<int> freq(26, 0);
        int ans = 0;

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (int cnt : freq) {
            ans += (cnt * (cnt + 1)) / 2;
        }

        return ans;
    }
};
