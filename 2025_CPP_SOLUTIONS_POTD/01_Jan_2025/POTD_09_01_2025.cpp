class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size(), sum  = 0, x =0;
        for(int i=0; i< n; i++ ){
            x = i;
            sum = 0;
            while( x != n){
                sum += arr[x];
                x++;
                if( sum == target){
                    return {i+1, x}; //since  we havet to return in 1 based index
                }
            }
        
        }
        return {-1};
    }
};