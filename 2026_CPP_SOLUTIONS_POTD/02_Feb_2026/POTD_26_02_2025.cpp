/*
    1. This function checks if two strings are isomorphic, meaning characters in one map uniquely to characters in the other.
    2. It uses two unordered_maps: mp1 maps characters from s1 to s2, and mp2 maps characters from s2 to s1.
    3. If the strings differ in length, they cannot be isomorphic, so return false immediately.
    4. For each character pair (c1, c2), if neither is mapped yet, establish a new mapping in both directions.
    5. If a mapping already exists, verify consistency; if mismatched, return false.
    6. If the loop completes without conflicts, the strings are isomorphic, so return true.
    7. Time Complexity: O(n), Space Complexity: O(n), where n is the length of the strings.
*/
class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        unordered_map<char,char> mp1; 
        unordered_map<char,char> mp2; 
        int n = s1.size();
        
        if(n != s2.size()) return false;
        
        for(int i = 0; i < n; i++) {
            char c1 = s1[i], c2 = s2[i];
            
            if(mp1.find(c1) == mp1.end() && mp2.find(c2) == mp2.end()) {
                mp1[c1] = c2;
                mp2[c2] = c1;
            } else {
                if(mp1[c1] != c2 || mp2[c2] != c1) return false;
            }
        }
        return true;
    }
};

// Key points:
// - The function ensures a one-to-one mapping between characters of both strings.
// - Two maps are used to prevent conflicts (e.g., two characters mapping to the same one).
// - Early exit if lengths differ saves unnecessary computation.
// - Consistency checks ensure mappings remain valid throughout.
// - Efficient O(n) solution using hash maps for constant-time lookups.
// - Space trade-off is necessary to guarantee uniqueness in both directions.
// - This approach is widely accepted as optimal for isomorphism checks.
