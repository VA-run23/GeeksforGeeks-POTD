/*
    1. This function finds the longest span where two binary arrays have the same sum.  
    2. It computes prefix differences: pSum = cumulative (a1[i] - a2[i]).  
    3. If pSum becomes zero, it means from index 0 to i both arrays have equal sum.  
    4. An unordered_map stores the first occurrence of each prefix difference.  
    5. If the same pSum reappears, the subarray between indices has equal sum in both arrays.  
    6. maxLen is updated with the longest such span found during traversal.  
    7. Time Complexity: O(n), Space Complexity: O(n).  
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

// Key points:
// - The problem reduces to finding the longest subarray with equal sum in both arrays.
// - By tracking prefix differences, we convert it into a "longest subarray with zero sum" problem.
// - The unordered_map ensures O(1) average lookup for prefix sums.
// - If pSum repeats, the subarray between those indices balances out differences.
// - This approach is optimal compared to brute force O(n^2).
