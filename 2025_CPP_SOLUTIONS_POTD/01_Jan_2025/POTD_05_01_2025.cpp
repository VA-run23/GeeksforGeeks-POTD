class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int pairs = 0;
        int left = 0;
        int right = arr.size() - 1;
        sort(arr.begin(), arr.end());
        while (left < right) {
            if ((arr[left] + arr[right]) < target) {
                pairs += (right - left); 
                left++;
            } else {
                right--;
            }
        }
        return pairs;
    }
};
