/*
    1. This code finds the sum of all elements *not* part of the Longest Increasing Subsequence (LIS) in the array 'arr'.
    2. It uses 'dp[i]' to store the length of the LIS ending at index 'i', and 'temp[i]' to trace predecessors to later reconstruct the LIS.
    3. In the nested loop, the LIS is built using dynamic programming: if 'arr[j] < arr[i]', update 'dp[i]' and mark 'j' in 'temp[i]'.
    4. After building 'dp', it finds the index of the last element of the LIS and calculates the total sum of the array.
    5. It then traces back the LIS using 'temp[]' starting from 'index', summing up the LIS elements.
    6. The final result is 'total - sum', which subtracts the LIS sum from the total to get the sum of non-LIS elements.
    7. Time complexity: O(n²) due to nested loops; Space complexity: O(n) for 'dp', 'temp', and extra variables.
*/

class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        vector<int>temp(arr.size(),0);
        vector<int>dp(arr.size(),1);
        for(int i = 0;i<arr.size();i++){
            for(int j = 0;j<i;j++){
                if(arr[j] < arr[i] && dp[i] <= dp[j]+1){
                    dp[i] = dp[j]+1;
                    temp[i] = j;
                }
            }
        }
        int total = 0;
        int index = -1,maxi = 0,size = 0;
        for(int i = 0;i<arr.size();i++){
            if(maxi <= dp[i]){
                maxi = dp[i];
                index = i;
            }
            total += arr[i];
        }
        size = maxi;
        int sum = arr[index];
        maxi--;
        while(maxi > 0){
            sum += arr[temp[index]];
            index = temp[index];
            maxi--;
        }
        return total-sum;
    }
};
