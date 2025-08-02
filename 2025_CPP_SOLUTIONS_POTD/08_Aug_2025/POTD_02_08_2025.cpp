/*
    1. We use a prefix sum approach where each element contributes +1 if it's greater than k, and -1 otherwise.
    2. The goal is to find the longest subarray where the net balance of +1s exceeds -1s, i.e., prefix sum > 0.
    3. If the prefix sum is positive at index i, the entire subarray from 0 to i is valid.
    4. If not, we check if prefix - 1 was seen before; this means a valid subarray exists from that earlier index to i.
    5. We store the first occurrence of each prefix value in the unordered_map to maximize subarray length.
    6. This ensures we always use the earliest index for a given prefix, helping us find the longest valid subarray.
    7. Time complexity is O(n), and space complexity is O(n) due to the hash map storing prefix indices.
*/

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> firstSeenIdx;
        int prefix = 0, maxLen = 0;

        for (int i = 0; i < arr.size(); ++i) {
            prefix += (arr[i] > k) ? 1 : -1;

            if (prefix > 0) {
                maxLen = i + 1;
            } else if (firstSeenIdx.count(prefix - 1)) {
                maxLen = max(maxLen, i - firstSeenIdx[prefix - 1]);
            }

            if (!firstSeenIdx.count(prefix)) {
                firstSeenIdx[prefix] = i;
            }
        }
        return maxLen;
    }
};
