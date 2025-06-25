/*
    1. The code builds a frequency array hash to count occurrences of each lowercase character in the string s.
    2. It first checks if all characters occur with the same frequency by comparing each non-zero count to an initial reference frequency.
    3. If all frequencies are equal, it returns true immediately.
    4. Otherwise, it tries reducing each character's frequency by 1 (simulating removal of a single character) one by one.
    5. For each attempt, it checks if the resulting frequencies become equal across all characters.
    6. If any such reduction leads to equal frequencies, it returns true; if none do, it returns false.
    7. Time Complexity is O(26²) ≈ O(1), and Space Complexity is O(26) ≈ O(1), as the alphabet is fixed in size.
*/


class Solution {
  public:
    bool sameFreq(string& s) {
        vector<int> hash(26,0);
        for(auto it:s){
            hash[it-'a']++;
        }
        
        int freq = -1;
        bool f = true;
        
        for(int i=0;i<26;i++){
            if(hash[i] == 0) continue;
            if(freq == -1) freq = hash[i];
            else if(freq != hash[i]) f = false;
        }
        
        if(f) return true;
        
        for(int i=0;i<26;i++){
            if(hash[i] > 0){
                // cout << i << " " << hash[i] << endl;
                hash[i]--;
                int req = -1;
                bool flag = true;
                for(int j=0;j<26;j++){
                    if(hash[j] == 0) continue;
                    if(req == -1) req = hash[j];
                    else if(hash[j] != req) flag = false;
                }
                hash[i]++;
                if(flag) return true;
            }
        }
        return false;
    }
};

