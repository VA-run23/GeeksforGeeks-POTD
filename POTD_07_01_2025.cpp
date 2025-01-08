class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int pairs = 0;
        int left = 0, right = n - 1;
        
        while (left < right) {
            if ((arr[left] + arr[right]) < target) {
                left++;
            } else if ((arr[left] + arr[right]) > target) {
                right--;
            } else { // equal condition
                if (arr[left] == arr[right]) {
                    int count = right - left + 1;
                    pairs += (count * (count - 1)) / 2;
                    break;
                } else {
                    int leftCount = 1, rightCount = 1;
                    while (left + 1 < right && arr[left] == arr[left + 1]) {
                        leftCount++;
                        left++;
                    }
                    while (right - 1 > left && arr[right] == arr[right - 1]) {
                        rightCount++;
                        right--;
                    }
                    pairs += leftCount * rightCount;
                    left++;
                    right--;
                }
            }
        }
        
        return pairs;
    }
};






