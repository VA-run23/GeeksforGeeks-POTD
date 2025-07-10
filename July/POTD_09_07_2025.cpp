/*
    1. This function computes the sum of minimums of all subarrays by using a monotonic stack and dynamic programming.
    2. It builds a 'nextSmall' array to find the next smaller element’s index to the right for each position.
    3. Using a stack, it iterates from end to start, maintaining the next smaller positions to optimize future calculations.
    4. The second loop calculates 'tillSum[i]', which stores the total contribution of arr[i] as the minimum in subarrays starting at 'i'.
    5. If no smaller element is found, arr[i] contributes to all subarrays ending after it; else it reuses 'tillSum[nextSmall[i]]' to avoid recomputation.
    6. Each value’s contribution is added to 'ans', which accumulates the total sum of all subarray minimums.
    7. Time Complexity: O(n), each index is pushed and popped at most once; Space Complexity: O(n), for the stack and auxiliary arrays.
*/


class Solution {
  public:
        int sumSubMins(vector<int> &arr) {
        // code here
        stack<int>st;
        int n = arr.size();
        int ans = 0;
        vector<int>tillSum(n,0);
        vector<int>nextSmall(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(i);
                continue;
            }
            nextSmall[i]=st.top();
            st.push(i);
        }
        for(int i=n-1;i>=0;i--){
            if(nextSmall[i]==-1){
                tillSum[i] = arr[i]*(n-i);
            }
            else{
                int idx = nextSmall[i];
                tillSum[i] = tillSum[idx]+arr[i]*(idx-i);
            }
            ans += tillSum[i];
        }
        return ans;
    }
};