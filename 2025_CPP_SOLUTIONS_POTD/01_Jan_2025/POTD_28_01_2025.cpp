class Solution {
  public:
    void backtrack(string s, vector<string> &result, int start) {
        if (start == s.length()) {
            result.push_back(s);
            return;
        }
        unordered_set<char> seen;
        for (int i = start; i < s.length(); i++) {
            if (seen.find(s[i]) == seen.end()) {
                seen.insert(s[i]);
                swap(s[start], s[i]);
                backtrack(s, result, start + 1);
                swap(s[start], s[i]);
            }
        }
    }

    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> result;
        sort(s.begin(), s.end());
        backtrack(s, result, 0);
        return result;
    }
};