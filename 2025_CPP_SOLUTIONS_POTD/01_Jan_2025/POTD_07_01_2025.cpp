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
                    // If the value at the left index is equal to the value at the right index
                if (arr[left] == arr[right]) {
                    // Calculate the count of elements between left and right indices (inclusive)
                    int count = right - left + 1;
                    
                    // Calculate the number of pairs that can be formed using the count of elements
                    pairs += (count * (count - 1)) / 2;
                    
                    // Break out of the loop since we have found equal elements at left and right indices
                    break;
                }else {
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






