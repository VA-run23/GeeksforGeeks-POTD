/*
    1. This function finds the smallest substring in 's' that contains all characters of 'p'.
    2. It first builds a frequency map of characters in 'p' to know what is required.
    3. Two pointers ('left' and 'right') define a sliding window over 's'.
    4. As 'right' expands, characters are added to the window map, and 'formed' tracks how many required chars match.
    5. When all required characters are matched ('formed == required'), the window shrinks from the left to minimize length.
    6. The smallest valid window is updated whenever a shorter substring is found.
    7. Time Complexity: O(|s| + |p|), Space Complexity: O(|s| + |p|).
*/
class Solution {
  public:
    string minWindow(string &s, string &p) {
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

// Key points:
// - Build frequency map of target string 'p'.
// - Use sliding window with two pointers to expand and contract.
// - Track how many required characters are satisfied using 'formed'.
// - Update minimum length whenever a valid window is found.
// - Shrink window from left to optimize size.
// - Return substring if found, else empty string.
// - Efficient solution with O(n) time using hash maps.
