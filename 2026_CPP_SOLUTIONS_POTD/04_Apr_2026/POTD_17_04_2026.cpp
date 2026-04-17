// Anagram Palindrome

/*
 *    1. We need to check if a string can be rearranged into a palindrome.
 *    2. A palindrome requires characters to appear in pairs, except possibly one.
 *    3. Count the frequency of each character in the string.
 *    4. Track how many characters have odd frequencies.
 *    5. If more than one character has an odd frequency, palindrome formation is impossible.
 *    6. Otherwise, the string can be rearranged into a palindrome.
 *    7. Time Complexity: O(n), Space Complexity: O(26) → O(1)
 */

class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        vector<int> freq(26, 0);
        int odds = 0;
        
        for (char c : s) {
            int idx = c - 'a';
            freq[idx]++;
            if (freq[idx] % 2 == 1) {
                odds++;
            } else {
                odds--;
            }
        }
        
        return odds <= 1;
    }
};

// Key Points
// 1. Palindrome requires at most one odd frequency character.
// 2. Frequency counting is done using a fixed-size array of 26.
// 3. Each character is processed in O(1) time.
// 4. The algorithm works only for lowercase English letters.
// 5. Odds counter increments/decrements dynamically during iteration.
// 6. Final check ensures palindrome feasibility.
// 7. Efficient solution with O(n) time and O(1) space.