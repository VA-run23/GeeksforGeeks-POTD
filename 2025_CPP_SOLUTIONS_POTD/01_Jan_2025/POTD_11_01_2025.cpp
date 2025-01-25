class Solution {
public:
    int longestUniqueSubstr(string s) {
        // code here
        unordered_map<char, int> chIdx;
        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (chIdx.find(s[i]) != chIdx.end()) {
                start = max(start, chIdx[s[i]] + 1);
            }
            chIdx[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};