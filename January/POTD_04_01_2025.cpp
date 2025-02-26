class Solution {
    public:
      int countTriplets(vector<int> &arr, int target) {
          int n = arr.size();
          int count = 0;
  
          for (int i = 0; i < n - 2; i++) {
              int left = i + 1;
              int right = n - 1;
  
              while (left < right) {
                  int sum = arr[i] + arr[left] + arr[right];
  
                  if (sum == target) {
                      count++;
                      left++;
                      right--;
                  } else if (sum < target) {
                      left++;
                  } else {
                      right--;
                  }
              }
          }
  
          return count;
      }
  };