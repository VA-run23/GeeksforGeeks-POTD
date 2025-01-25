class Solution {
public:
    int maxWater(vector<int> &arr) {
        //code here
        if (arr.size() <= 1) return 0;

        int left = 0, right = arr.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int height = min(arr[left], arr[right]);
            maxWater = max(maxWater, width * height);

            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};