/*
    '1. This code generates all possible words from a sequence of digits using a mobile keypad mapping (e.g., 2 → "abc", 3 → "def").
    2. The 'solve' function uses recursion to build combinations character by character, appending letters from the current digit to a temporary string.
    3. If a digit maps to no letters (like 0 or 1), it's skipped by directly calling the next recursive step.
    4. The loop inside 'solve' triggers a new recursive call for each character mapped to the current digit, forming a branching tree of calls.
    5. Once all digits are processed ('i == n'), the built string 'temp' is added to the final answer list 'ans'.
    6. 'possibleWords' initializes the keypad mapping and starts the recursive process with an empty string.
    7. Time Complexity: O(4ⁿ) in worst case (digits like 7 or 9 map to 4 letters); Space Complexity: O(n) for recursion depth and temporary string storage.

    🔑 Key Points:
    - Recursive calls inside the loop create a tree structure, exploring all combinations depth-first.
    - 'temp + keys[arr[i]][j]' builds the string progressively, one character per digit.
    - Passing 'ans' and 'keys' avoids static state issues, ensuring clean scope and reusability.
*/

class Solution {
  public:
    void solve(int i, int n, vector<int>&arr, string temp, vector<string>&ans, vector<string>keys) {

        if(i==n) {
            ans.push_back(temp);
            return;
        }
        

        if (keys[arr[i]].empty()) {
            solve(i + 1, n, arr, temp, ans, keys);
            return;
        }
        
        for(int j=0; j<keys[arr[i]].size(); j++) {
            solve(i+1, n, arr, temp+keys[arr[i]][j], ans, keys);
        }
    }
    
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string>keys = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        solve(0, arr.size(), arr, "", ans, keys);
        return ans;
    }
};