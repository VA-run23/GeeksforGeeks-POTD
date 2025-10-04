/*
    1. This code solves the "Expression Add Operators" problem by generating all valid expressions from a digit string 's' that evaluate to a given 'target'.
    2. It uses Depth-First Search (DFS) to explore all possible placements of '+', '-', and '*' operators between digits, while tracking the current value ('curVal') and last operand ('lastVal') for multiplication handling.
    3. The base case checks if the entire string has been processed ('idx == s.size()') and if the expression evaluates to the target, then adds it to the result list 'ans'.
    4. The loop generates substrings ('part') from the current index and converts them to numbers using 'stoll(part)'—which safely handles large values as 'long long'.
    5. Leading zeros are skipped (e.g., "05") to ensure only valid operands are considered, as per problem constraints.
    6. For each recursive call, it tries all three operators and updates 'curVal' and 'lastVal' accordingly, especially handling multiplication with precedence.
    7. Time Complexity: O(n × 4ⁿ) in worst case due to recursive branching and string operations; Space Complexity: O(n × 4ⁿ) for recursion stack and storing expressions.
*/

class Solution {
  public:
  vector<string> ans;
    void dfs(string &s, int target, int idx, long long curVal, long long lastVal, string expr) {
        if (idx == s.size()) {
            if (curVal == target) {
                ans.push_back(expr);
            }
            return;
        }

        for (int j = idx; j < s.size(); j++) {
            if (j > idx && s[idx] == '0') break;
            string part = s.substr(idx, j - idx + 1);
            long long num = stoll(part);
            if (idx == 0) {
                dfs(s, target, j + 1, num, num, part);
            } else {
                dfs(s, target, j + 1, curVal + num, num, expr + "+" + part);
                dfs(s, target, j + 1, curVal - num, -num, expr + "-" + part);
                dfs(s, target, j + 1, curVal - lastVal + lastVal * num, lastVal * num, expr + "*" + part);
            }
        }
    }
    vector<string> findExpr(string &s, int target) {
        // code here
        ans.clear();
        dfs(s, target, 0, 0, 0, "");
        sort(ans.begin(), ans.end()); 
        return ans;
        
    }
};