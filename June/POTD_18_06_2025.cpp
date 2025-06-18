/*
    1. The 'isPalindrome' function checks whether a given substring is a palindrome by comparing characters from both ends.
    2. The 'back' function recursively partitions the string while ensuring each partitioned segment is a palindrome.
    3. If the entire string is partitioned, the 'curPart' list is added to the 'ans' list, storing valid palindromic partitions.
    4. The function iterates through possible substrings; if valid, they are added recursively, ensuring all partitions are explored.
    5. The recursion backtracks by removing the last added substring when moving to the next partition possibility.
    6. The 'palinParts' function initializes necessary containers and invokes recursion to generate all palindromic partitions.
    7. Time Complexity: 'O(2^N * N)', as there are exponentially many partitions, each taking linear time. Space Complexity: 'O(N^2)', considering recursive depth and stored partitions.
*/

class Solution {
  public:
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void back(int start, string &s, vector<string> &curPart, vector<vector<string>> &ans) {
        if (start == s.size()) {
            ans.push_back(curPart);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                curPart.push_back(s.substr(start, end - start + 1));
                back(end + 1, s, curPart, ans);
                curPart.pop_back();
            }
        }
    }

    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> ans;
        vector<string> curPart;
        back(0, s, curPart, ans);
        return ans;
    }
};
