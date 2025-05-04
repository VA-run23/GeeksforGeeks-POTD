/*
    1. Create a set to store unique characters and determine the count required for a valid substring.
    2. Use a sliding window approach with a frequency map to track occurrences of characters in the window.
    3. Expand the window by iterating from left to right, increasing frequency counts.
    4. Once all required unique characters are present, start minimizing the window from the left.
    5. Update the minimum window size whenever all characters are included in the current window.
    6. Continue adjusting the left pointer while ensuring the smallest valid window is tracked.
    7. Time Complexity: O(N), since each character is processed at most twice. Space Complexity: O(U), where U is the number of unique characters.
*/


class Solution {
  public:
    int findSubString(string& str) {
        // code here
        unordered_set<char>unqChars(str.begin(), str.end()); 
        int req =unqChars.size(); 
        unordered_map<char, int> freq;
        int left = 0, minL = INT_MAX, cnt = 0;
        
        for (int right = 0; right < str.size(); ++right) {
            freq[str[right]]++;
            if (freq[str[right]] == 1) cnt++; 
            
            while (cnt == req) { 
                minL = min(minL, right - left + 1);
                freq[str[left]]--;
                if (freq[str[left]] == 0) cnt--;
                left++; 
            }
        }
        
        return minL;
    }
};