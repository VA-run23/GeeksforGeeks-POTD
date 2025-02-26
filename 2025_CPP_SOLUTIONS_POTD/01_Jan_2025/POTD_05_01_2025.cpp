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
////EXPLANATION:
//Since we increment the 'left' pointer after counting pairs, this ensures we account for all unique pairs involving the current 'left' element with every element between 'left' and 'right'.
// By adding (right - left), we count the number of such unique pairs, as each element between 'left' and 'right' forms a pair with 'arr[left]' that sums up to less than the target.
