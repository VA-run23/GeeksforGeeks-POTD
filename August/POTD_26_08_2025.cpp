/*
    1. This function checks if string s1 is a subsequence of string s2.
    2. It uses two pointers: 'i' for s1 and 'j' for s2, both starting at index 0.
    3. The loop continues as long as both pointers are within their respective string lengths.
    4. If characters at s1[i] and s2[j] match, it moves the s1 pointer forward.
    5. Regardless of a match, the s2 pointer always moves forward to scan the next character.
    6. If all characters of s1 are found in order within s2, i will reach s1.size().
    7. Time Complexity: O(n + m), Space Complexity: O(1) — efficient and memory-light.
*/

class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        // code here

        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) i++;
            j++;
        }
        return i == s1.size();
    }
};
