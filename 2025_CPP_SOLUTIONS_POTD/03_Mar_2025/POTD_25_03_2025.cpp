class Solution {
  public:
    unordered_map<string, int> dp;
    
    int helper(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        string key = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);
        if (dp.find(key) != dp.end()) return dp[key];
        
        int ways = 0;
        for (int k = i + 1; k < j; k += 2) {
            int lTrue = helper(s, i, k - 1, true);
            int lFalse = helper(s, i, k - 1, false);
            int rTrue = helper(s, k + 1, j, true);
            int rFalse = helper(s, k + 1, j, false);
            
            if (s[k] == '&') {
                if (isTrue) ways += lTrue * rTrue;
                else ways += lFalse * rFalse + lTrue * rFalse + lFalse * rTrue;
            } 
            else if (s[k] == '|') {
                if (isTrue) ways += lTrue * rTrue + lTrue * rFalse + lFalse * rTrue;
                else ways += lFalse * rFalse;
            } 
            else if (s[k] == '^') {
                if (isTrue) ways += lTrue * rFalse + lFalse * rTrue;
                else ways += lTrue * rTrue + lFalse * rFalse;
            }
        }
        return dp[key] = ways;
    }
    
    int countWays(string &s) {
        // code here
        dp.clear();
        return helper(s, 0, s.size() - 1, true);
    }
};