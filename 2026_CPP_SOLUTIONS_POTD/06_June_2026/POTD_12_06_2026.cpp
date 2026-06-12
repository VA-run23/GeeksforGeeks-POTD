// Check if a String is Repetition of its Substring of K Length

/*
 *    1. The problem asks to verify if a string can be divided into substrings of length k.
 *    2. Each substring must be identical or at most two distinct substrings can exist.
 *    3. The string length must be divisible by k, otherwise return false.
 *    4. Use a hash map to count occurrences of each substring of length k.
 *    5. If more than two distinct substrings are found, return false immediately.
 *    6. Ensure that at most one substring repeats more than once.
 *    7. Time Complexity: O(n/k), Space Complexity: O(n/k) due to substring storage.
 */

class Solution {
  public:
    bool kSubstr(string &s, int k) {
        // code here
        int n = s.size();
        if (n % k)
            return false;
        
        unordered_map<string, int> um;
        
        for (int i = 0; i < n; i += k) {
            um[s.substr(i, k)]++;
            if (um.size() > 2)
                return false;
        }
        
        int c = 0;
        for (auto z : um) {
            if ((z.second) > 1)
                c++;
            if (c > 1)
                return false;
        }
        
        return true;
    }
};

// Key Points
// 1. String length must be divisible by k.
// 2. At most two distinct substrings are allowed.
// 3. Use hash map to track substring counts.
// 4. Early termination if more than two substrings appear.
// 5. Only one substring can repeat multiple times.
// 6. Efficient substring extraction using s.substr(i, k).
// 7. Time O(n/k), Space O(n/k).