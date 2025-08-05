
/*
    1. The function isPalinSent checks if a given string is a palindrome sentence, ignoring non-alphanumeric characters and case.
    2. It uses two pointers: 'i' starting from the beginning and 'j' from the end of the string.
    3. Both pointers skip non-alphanumeric characters using isalnum() to focus only on valid characters.
    4. Characters at positions 'i' and 'j' are compared after converting them to lowercase using tolower().
    5. If any mismatch is found, the function returns false, indicating the string is not a palindrome.
    6. If all valid characters match symmetrically, the function returns true.
    7. Time Complexity: O(n), where n is the length of the string; Space Complexity: O(1), as no extra space is used.
*/

class Solution {
  public:
    bool isPalinSent(string &s) {
        // code here
        int i = 0, j = s.size() - 1;

        while (i < j) {

            while (i < j && !isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;

            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};