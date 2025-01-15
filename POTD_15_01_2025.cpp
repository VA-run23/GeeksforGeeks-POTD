class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        //code here
        unordered_map<int, int> sumIdx; 
        int sum = 0, mxLen = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum == k) {
                mxLen = i + 1;
            }

            if (sumIdx.find(sum) == sumIdx.end()) {
                sumIdx[sum] = i;
            }

            if (sumIdx.find(sum - k) != sumIdx.end()) {
                mxLen = max(mxLen, i - sumIdx[sum - k]);
            }
        }

        return mxLen;
    }
};

