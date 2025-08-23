/*
    1. This code solves the "Book Allocation Problem" using binary search to minimize the maximum pages a student reads.
    2. The helper function isPossible checks if it's feasible to allocate books such that no student reads more than 'mid' pages.
    3. In findPages, we first check if the number of students exceeds the number of books—if so, allocation is impossible.
    4. We calculate the total sum of pages and the maximum single book size to define the binary search range.
    5. Binary search is applied between max book size and total pages to find the minimum feasible maximum.
    6. If allocation is possible with current mid, we try to minimize further; otherwise, we increase the lower bound.
    7. Time Complexity: O(N * log(S)), where N = number of books, S = sum of pages; Space Complexity: O(1).
*/

class Solution {
  public:
  bool isPossible(vector<int> &arr, int k,int mid){
      int sum=0,student=1;
      for(int x:arr){
          sum+=x;
          if(sum>mid){
              student++;
              sum=x;
          }
          
      }
      return student<=k;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size()) return -1;
        int sum=0,mx=INT_MIN;
        for(int x:arr){
            sum+=x;
            mx=max(mx,x);
        }
        int low=mx,high=sum,mid,ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            if(isPossible(arr,k,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};