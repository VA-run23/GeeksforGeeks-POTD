/* 
1. The countSubstr function calculates the number of substrings with exactly k distinct characters 
   by subtracting the count of substrings with at most (k-1) distinct characters from at most k. 

2. The atMostK function uses a sliding window approach to count the number of substrings 
   containing at most k distinct characters efficiently. 

3. It maintains a frequency array (vector) to track character occurrences within the window 
   and a distinct counter to track unique characters. 

4. The right pointer expands the window by adding new characters, increasing distinct count if necessary. 

5. If distinct characters exceed k, the left pointer shrinks the window while reducing the count 
   until it becomes valid again. 

6. For each valid window ending at the right pointer, the number of substrings contributed is 
   (right - left + 1), ensuring all possible substrings are counted. 

7. The function efficiently runs in O(n) time complexity, processing each character at most twice, 
   making it suitable for large inputs (up to 10^6 characters). 
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