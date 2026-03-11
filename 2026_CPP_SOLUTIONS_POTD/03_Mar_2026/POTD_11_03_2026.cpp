// Sum of Subarray Minimums

/*
 *    1. We need to calculate the sum of minimums of all subarrays.
 *    2. Each element contributes as the minimum in certain subarrays.
 *    3. Use a monotonic stack to find the next smaller element for each index.
 *    4. Store cumulative contributions in a helper array (tillSum).
 *    5. If no smaller element exists, contribution extends to the end of the array.
 *    6. Otherwise, link contributions through the next smaller index.
 *    7. Time Complexity: O(n), Space Complexity: O(n)
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

// Key Points
// 1. Each element contributes to subarrays where it is the minimum.
// 2. Monotonic stack helps in finding next smaller efficiently.
// 3. Contributions are cumulative and reused via tillSum.
// 4. If no smaller element exists, contribution extends to array end.
// 5. Avoids brute force enumeration of subarrays.
// 6. Achieves linear time complexity.
// 7. Uses O(n) extra space for helper arrays.
