class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int start = 0, resStart = 0, resEnd = 0;
        int minVal = arr[0], maxVal = arr[0];

        for (int end = 0; end < n; end++) {
            minVal = min(minVal, arr[end]);
            maxVal = max(maxVal, arr[end]);

            while (maxVal - minVal > x) {
                start++;
                minVal = *min_element(arr.begin() + start, arr.begin() + end + 1);
                maxVal = *max_element(arr.begin() + start, arr.begin() + end + 1);
            }

            if (end - start > resEnd - resStart) {
                resStart = start;
                resEnd = end;
            }
        }
        return vector<int>(arr.begin() + resStart, arr.begin() + resEnd + 1);
    }
};