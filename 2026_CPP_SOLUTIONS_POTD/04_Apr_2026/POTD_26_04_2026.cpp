// Common Elements in Three Arrays

/*
 *    1. Convert first two arrays into sets for fast lookup
 *    2. Iterate through the third array to check membership in both sets
 *    3. Use a separate set to avoid duplicates in the result
 *    4. Push elements into the answer vector only if unseen
 *    5. This ensures uniqueness and correctness of common elements
 *    6. Return the final vector containing common elements
 *    7. Time Complexity: O(n1 + n2 + n3), Space Complexity: O(n1 + n2 + n3)
 */

class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        set<int> aa(a.begin(), a.end());
        set<int> bb(b.begin(), b.end());
        
        vector<int> ans;
        set<int> seen; 
        
        for (auto &i : c) {
            if (aa.find(i) != aa.end() && bb.find(i) != bb.end()) {
                if (seen.find(i) == seen.end()) { 
                    ans.push_back(i);
                    seen.insert(i);
                }
            }
        }
        return ans;
    }
};

// Key Points
// 1. Sets are used for O(1) average lookup
// 2. Third array is iterated to check membership
// 3. Duplicate handling is done via 'seen' set
// 4. Ensures correctness even with repeated elements
// 5. Works for unsorted arrays as well
// 6. Output preserves order of discovery from third array
// 7. Overall efficient solution with linear complexity