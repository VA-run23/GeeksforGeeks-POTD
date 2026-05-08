// Remove Invalid Parentheses

/*
 *    1. The problem is to remove the minimum number of invalid parentheses.
 *    2. The goal is to generate all possible valid strings after removal.
 *    3. A helper function checks if a string is valid by balancing parentheses.
 *    4. DFS is used to explore all removal possibilities recursively.
 *    5. Duplicate results are avoided by using a set.
 *    6. The number of removals is calculated by scanning the input string.
 *    7. Time Complexity: O(2^n * n), Space Complexity: O(n * 2^n)
 */

class Solution {
private:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }

    void dfs(string s, int start, int l_rem, int r_rem, set<string>& res) {
        if (l_rem == 0 && r_rem == 0) {
            if (isValid(s)) {
                res.insert(s);
            }
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (i != start && s[i] == s[i - 1]) continue;
            if (s[i] == '(' && l_rem > 0) {
                dfs(s.substr(0, i) + s.substr(i + 1), i, l_rem - 1, r_rem, res);
            }
            if (s[i] == ')' && r_rem > 0) {
                dfs(s.substr(0, i) + s.substr(i + 1), i, l_rem, r_rem - 1, res);
            }
        }
    }

public:
    vector<string> validParenthesis(string &s) {
        int l_rem = 0, r_rem = 0;
        for (char c : s) {
            if (c == '(') {
                l_rem++;
            } else if (c == ')') {
                if (l_rem > 0) {
                    l_rem--;
                } else {
                    r_rem++;
                }
            }
        }

        set<string> valid_strings;
        dfs(s, 0, l_rem, r_rem, valid_strings);

        if (valid_strings.empty()) {
            return {""};
        }

        return vector<string>(valid_strings.begin(), valid_strings.end());
    }
};

// Key Points
// 1. Uses DFS to explore all removal possibilities.
// 2. Validity check ensures balanced parentheses.
// 3. Set avoids duplicate results.
// 4. Removal counts are precomputed before DFS.
// 5. Skips consecutive duplicates to optimize search.
// 6. Returns all valid strings after minimal removals.
// 7. Exponential time complexity due to recursive exploration.