/*
   1. The function countSubstr(s, k) calculates the number of substrings with exactly k distinct characters 
      by subtracting substrings with at most (k-1) distinct characters from substrings with at most k distinct characters.
   2. The helper function atMostK(s, k) uses a sliding window approach to count substrings with at most k distinct characters.
   3. It maintains a frequency array (size 26 for lowercase letters) to track character counts in the current window.
   4. The variable 'distinct' keeps track of how many unique characters are currently in the window.
   5. If distinct exceeds k, the left pointer is moved forward while updating frequencies until the window is valid again.
   6. For each valid window ending at 'right', the number of substrings contributed is (right - left + 1), 
      since all substrings starting between left and right are valid.
   7. Time Complexity: O(n) where n = length of string (each character processed once); 
      Space Complexity: O(26) = O(1) for frequency array.
*/

/* Key Points:
- Sliding window ensures efficient substring counting without recomputation.
- Difference of atMostK(s, k) and atMostK(s, k-1) isolates substrings with exactly k distinct characters.
- Frequency array avoids costly set operations, keeping space constant.
*/

class Solution {
public:
    int countSubstr(string s, int k) {
        // code here
        return atMostK(s, k) - atMostK(s, k - 1);
    }
    
private:
    int atMostK(const string &s, int k) {
        if (k < 0)
            return 0;
        
        int n = s.size();
        int count = 0, distinct = 0;
        vector<int> freq(26, 0);
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (freq[s[right] - 'a'] == 0)
                distinct++;
            
            freq[s[right] - 'a']++;
            
            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0)
                    distinct--;
                left++;
            }
            
            count += (right - left + 1);
        }
        return count;
    }
};