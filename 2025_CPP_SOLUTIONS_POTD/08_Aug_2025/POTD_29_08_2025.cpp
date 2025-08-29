/*
    1. This function finds the smallest substring in 's' that contains all characters (including duplicates) of string 'p'.
    2. It uses two hash maps: 'freq' to store the frequency of characters in 'p', and 'window' to track the current window in 's'.
    3. The 'required' variable counts how many unique characters from 'p' must be matched, and 'formed' tracks how many are currently matched.
    4. The sliding window expands with 'right' and contracts with 'left' to find the minimum length substring that satisfies the condition.
    5. When all required characters are matched ('formed == required'), it tries to shrink the window from the left to find a smaller valid substring.
    6. If a smaller valid window is found, it updates 'minLen' and 'start' to record its position.
    7. Time Complexity: O(|s| + |p|), Space Complexity: O(|s| + |p|) due to hash maps storing character frequencies.
*/                  

class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        unordered_map<char, int> freq;
        for (char c : p) freq[c]++;
        
        int required = freq.size(), formed = 0;
        unordered_map<char, int> window;
        int left = 0, right = 0, minLen = INT_MAX, start = 0;
        
        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            if (freq.count(c) && window[c] == freq[c]) formed++;
            
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char d = s[left];
                window[d]--;
                if (freq.count(d) && window[d] < freq[d]) formed--;
                left++;
            }
            right++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};


