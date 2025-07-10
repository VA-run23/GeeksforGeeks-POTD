/*
    1. This function computes the maximum sum of any two adjacent elements in the array.
    2. It initializes 'ans' to 0 to store the maximum sum and gets the size 'n' of the array.
    3. The loop uses two pointers 'l' and 'r' that iterate simultaneously, where 'r = l + 1'.
    4. For each pair '(arr[l], arr[r])', it calculates their sum and updates 'ans' if the sum is greater.
    5. This way, it checks all adjacent pairs from start to end of the array in linear time.
    6. The function finally returns the maximum adjacent pair sum found.
    7. Time Complexity: O(n), as each adjacent pair is checked once; Space Complexity: O(1), no extra space used.
*/

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int ans=0;
        int n=arr.size();
        for(int l=0,r=1;l<n && r<n;++l,++r){
            ans=max(ans,arr[r]+arr[l]);
        }
        return ans;
    }
};