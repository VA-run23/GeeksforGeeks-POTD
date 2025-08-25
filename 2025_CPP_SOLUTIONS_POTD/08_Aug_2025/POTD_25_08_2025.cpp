/*
    1. The function aims to maximize the median of an array after performing at most k increment operations.
    2. It first sorts the array to make median calculations and comparisons easier.
    3. For odd-sized arrays, it starts from the middle and tries to distribute k across the right half to raise the median.
    4. It accumulates the sum and count of elements from the median onward, stopping if the average can't surpass the next element.
    5. For even-sized arrays, it includes both middle elements and follows a similar strategy, tracking a breakpoint to decide if median can be raised.
    6. If the breakpoint is at the left middle, it directly returns the average of the two middle elements after adding k.
    7. Time complexity is O(n log n) due to sorting; space complexity is O(1) as no extra space is used beyond variables.
*/

class Solution {
  public:
    int maximizeMedian(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(n%2 != 0){
            int curr_sum=0;
            int count=0;
            for(int i=n/2;i<n;i++){
                curr_sum+=arr[i];
                count++;
                if(i<=n-2){
                    if((curr_sum+k)/count <= arr[i+1]){
                        break;
                    }
                }
            }
            return (curr_sum+k)/count;
        }
        else{
            
            int curr_sum=0;
            int count=0;
            int breakpoint=-1;
            for(int i=n/2-1;i<n;i++){
                curr_sum+=arr[i];
                count++;
                if(i<=n-2){
                    if((curr_sum+k)/count <= arr[i+1]){
                        breakpoint=i;
                        break;
                    }
                }
            }
            if(breakpoint==n/2-1){
                return (arr[n/2-1]+k+arr[n/2])/2;
            }
            return (curr_sum+k)/count;
            
        }
    }
};