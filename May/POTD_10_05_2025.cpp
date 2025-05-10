// The function finds the longest subarray where count of elements > k 
// is greater than the count of elements <= k.
// It converts elements into +1 (greater than k) and -1 (less than or equal to k).
// A prefix sum is maintained to track balance between +1 and -1 values.
// A hash map stores the first occurrence of each prefix sum for quick lookup.
// If the prefix sum becomes positive, the whole subarray from start is valid.
// If the prefix sum was seen before, it helps find longest valid subarray efficiently.
// Time Complexity: O(N), Space Complexity: O(N), where N is the size of the array.

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size(), psum = 0, maxLen = 0;
        vector<int> mod(n);
        unordered_map<int, int> pMap;

        for (int i = 0; i < n; i++) mod[i] = (arr[i] > k) ? 1 : -1;

        for (int i = 0; i < n; i++) {
            psum += mod[i];
            if (psum > 0) maxLen = i + 1;
            if (pMap.count(psum - 1)) maxLen = max(maxLen, i - pMap[psum - 1]);
            if (!pMap.count(psum)) pMap[psum] = i;
        }

        return maxLen;
    }
};
