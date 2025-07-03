/* 
  1. This code finds the length of the longest substring in 's' with exactly 'k' unique characters using a sliding window.
  2. It maintains two pointers 'i' and 'j' to define the current window, and a hash map 'mp' to count character frequencies.
  3. The window expands by incrementing 'j' and adding characters into 'mp' until the number of unique characters exceeds 'k'.
  4. When 'mp.size() > k', the window shrinks from the left by moving 'i' forward and updating the map accordingly.
  5. Each time 'mp.size() == k', the code updates 'mx' to the maximum length of such a valid window.
  6. The loop runs till 'j' reaches the end of the string, ensuring all possible windows are evaluated.
  7. Time complexity: O(n), Space complexity: O(k); n is the length of the string and k is the number of unique characters.
*/

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n=s.length();
        unordered_map<int,int>mp;
        
        int i=0;
        int j=0;
        int mx=-1;
        while(j < n){
            
           mp[s[j]]++;
           
           while(mp.size() > k){
               mp[s[i]]--;
               if(mp[s[i]]==0) mp.erase(s[i]);
               i++;
           }
            
         if(mp.size() == k)  mx=max(mx,j-i+1);
         
            j++;
            
        }
        return mx;
        
    }

};