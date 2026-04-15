// URLify a String

/*
 *    1. Replace spaces in a string with '%20'
 *    2. Iterate through each character of the string
 *    3. Check if the current character is a space
 *    4. If space is found, replace it with '%20'
 *    5. Adjust index to skip over newly inserted characters
 *    6. Continue until the end of the string
 *    7. Time Complexity: O(n), Space Complexity: O(1) (in-place)
 */

class Solution {
  public:
    string URLify(string &s) {
        // code here
        for(int i = 0; i<s.size(); i++){
            if(s[i] == ' '){
                s.replace(i, 1, "%20");
                i += 2;
            }
        }
        return s;
    }
};

// Key Points
// 1. Problem focuses on replacing spaces with '%20'
// 2. Uses in-place modification of the string
// 3. Iterates through each character sequentially
// 4. Efficiently handles multiple spaces
// 5. Index adjustment prevents re-checking inserted characters
// 6. Works directly on the input string reference
// 7. Achieves O(n) time and O(1) space complexity