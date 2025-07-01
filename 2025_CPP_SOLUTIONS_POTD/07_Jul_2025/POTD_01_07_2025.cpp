/*
    1. Initialize a sliding window with pointers 'left' and 'right', and use an unordered map to count character frequencies.
    2. Expand the window by incrementing 'right' and update the character frequency map.
    3. While the current window size is at least 'k', check if the number of distinct characters is 'k-1'.
    4. If the condition is met, increment the result 'ans' as the current substring meets the requirement.
    5. Shrink the window from the left by decreasing the frequency of 's[left]', and erase it if frequency becomes zero.
    6. Move 'left' forward to maintain window size constraints and repeat the process.
    7. Return the total count of substrings of length 'k' with exactly 'k-1' distinct characters.

    Time Complexity: O(n), as each character is added and removed from the hashmap at most once.
    Space Complexity: O(k), for storing at most 'k' characters in the hashmap.
*/

class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<char,int>hash;
        int n=s.length();
        int left=0,right=0;
        int ans=0;
        while(right<n){
            hash[s[right]]++;
            while((right-left+1)>=k && left<n){
                if(hash.size()==k-1)ans++;
                hash[s[left]]--;
                if(hash[s[left]]==0)hash.erase(s[left]);
                left++;
            }
            right++;
        }
        return ans;
        
    }
};