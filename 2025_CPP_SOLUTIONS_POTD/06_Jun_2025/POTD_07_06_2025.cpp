/*
    1. Create a hash map to store the first occurrence of each prefix sum difference.
    2. Traverse the arrays and compute the difference: 'pSum += (a1[i] - a2[i])'.
    3. If 'pSum' becomes 0, it means the subarray from the start has equal sum in both arrays.
    4. If 'pSum' was seen before, the span between previous index and current index has equal sum.
    5. Update 'maxLen' to store the longest span found so far.
    6. If 'pSum' is new, store its index in the hash map for future reference.
    7. Finally, return 'maxLen' as the length of the longest span with the same sum.
*/

class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n = a1.size();
        unordered_map<int, int> pMap;
        int maxLen = 0;
        int pSum = 0;
    
        for (int i = 0; i < n; i++) {
            pSum += (a1[i] - a2[i]);
    
            if (pSum == 0) {
                maxLen = i + 1;
            }
    
            if (pMap.find(pSum) != pMap.end()) {
                maxLen = max(maxLen, i - pMap[pSum]);
            } else {
                pMap[pSum] = i;
            }
        }
    
        return maxLen;
    }
};