class Solution {
  public:
    int maxLen(vector<int> &arr) {
        //Your code here
        unordered_map<int, int> prefixSumIndices;
        prefixSumIndices[0] = -1;
        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < arr.size(); ++i) {
            prefixSum += (arr[i] == 1) ? 1 : -1;
            if (prefixSumIndices.find(prefixSum) != prefixSumIndices.end()) {
                maxLen = max(maxLen, i - prefixSumIndices[prefixSum]);
            } else {
                prefixSumIndices[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
