// Remove Spaces

/*
 *    1. Given a string, the task is to remove all spaces.
 *    2. Iterate through each character of the string.
 *    3. Check if the character is not a space.
 *    4. If not a space, append it to the result string.
 *    5. Continue until all characters are processed.
 *    6. Return the final string without spaces.
 *    7. Time Complexity: O(n), Space Complexity: O(n)
 */

class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string result;
        for (char c : s) {
            if (c != ' ') result.push_back(c);
        }
        return result;
    }
};

// Key Points
// 1. Simple linear traversal of the string.
// 2. Efficiently removes spaces without extra libraries.
// 3. Preserves the order of non-space characters.
// 4. Works for both leading, trailing, and middle spaces.
// 5. Uses an auxiliary string to build the result.
// 6. Handles empty strings gracefully.
// 7. Optimal for single-pass space removal.