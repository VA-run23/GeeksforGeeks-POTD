/*
    1. This function finds the length of the longest substring with exactly k distinct characters.
    2. It uses a sliding window approach with two pointers: 'i' (end) and 'x' (start).
    3. An unordered_map 'mp' tracks the frequency of characters in the current window.
    4. If the map size exceeds k, the left pointer 'x' is moved forward while reducing counts.
    5. When the map size equals k, the window length is checked and maximum length updated.
    6. Time Complexity: O(n), since each character is processed at most twice (insert/remove).
    7. Space Complexity: O(k), as the map stores at most k distinct characters.
*/

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char, int> mp;
        int x = 0, ans = 0, n = s.size();
        
        for(int i = 0; i<n; i++){
            mp[s[i]]++;
            while(mp.size() > k){
             
                    mp[s[x]]--;
                    if(mp[s[x]] == 0)mp.erase(s[x]);
                    x++;
                
            }
            if(mp.size() == k)ans = max(ans, i - x + 1);
        }
        return ans == 0? -1: ans;
    }
};

// Key points:
// - Sliding window ensures efficient traversal without re-checking substrings.
// - Map tracks character frequencies to maintain distinct count.
// - Shrinking window when distinct count exceeds k keeps substring valid.
// - Answer updated only when exactly k distinct characters are present.
// - Returns -1 if no substring with k distinct characters exists.
