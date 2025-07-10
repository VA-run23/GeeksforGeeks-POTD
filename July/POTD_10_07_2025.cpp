/*
1. This function finds the longest word in `words` such that all of its prefixes also exist in the list.
2. It sorts the list lexicographically to ensure consistent prefix checking and prioritizes smaller strings when lengths match.
3. A hash map `ump` stores the frequency of each word for quick prefix presence lookup.
4. For every word, it builds prefix strings character by character and checks if all prefixes exist in the map.
5. If a missing prefix is found, it skips the current word; otherwise, it compares its length to the longest valid word seen so far.
6. If the current word is longer, it's stored as the answer with updated length.
7. Time Complexity: O(n * m), where n = number of words, m = max word length; Space Complexity: O(n * m), for map and result storage.
*/

class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        sort(words.begin(), words.end());
        unordered_map<string, int>ump;
        for(auto &i : words)    ump[i]++;
        string s;   int l = 0;
        for(auto &i : words){
            string x;    int n = i.size();
            for(int j = 0; j < n; j++){
                x += i[j];
                if(!ump[x]){
                    n = 0;  break;
                }
            }
            if(n > l){
                s = i;  l = n;
            }
        }
        return s;
    }
};