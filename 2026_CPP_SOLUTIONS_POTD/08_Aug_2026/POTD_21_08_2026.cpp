// Transform String

/*
 *    1. The problem asks to transform string s1 into s2 using minimum operations.
 *    2. First check if lengths of s1 and s2 are equal; if not, return -1.
 *    3. Count character frequencies in both strings using a hash map.
 *    4. If frequencies mismatch, transformation is impossible → return -1.
 *    5. Traverse from the end of both strings: 
 *       - If characters match, move both pointers.
 *       - If not, increment operations and move only s1 pointer.
 *    6. Continue until one string is fully traversed.
 *    7. Time Complexity: O(n), Space Complexity: O(1).
 */

class Solution {
  public:
    int transform(string &s1, string &s2) {
        // code here
        if (s1.size() != s2.size()) return -1;
        
        unordered_map<char, int> mp;
        for (char x: s1) mp[x]++;
        for (char x: s2) {
            mp[x]--;
            if (mp[x] == 0) mp.erase(x);
        }
        
        if (mp.size()) return -1;
        
        int i = s1.size() - 1, j = s2.size() - 1;
        int ans = 0;
        while (i >= 0 && j >= 0) {
            if (s1[i] == s2[j]) {
                i--; j--;
            } else {
                ans++; i--;
            }
        }
        
        return ans;
    }
};

// Key Points
// 1. Checks length equality first.
// 2. Uses hash map to verify character frequency match.
// 3. If mismatch, transformation impossible → return -1.
// 4. Traverses from end of both strings.
// 5. Matches characters directly, otherwise counts operation.
// 6. Operations = number of mismatches while aligning s1 to s2.
// 7. Runs in O(n) time with O(1) extra space.