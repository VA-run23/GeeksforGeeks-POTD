
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        if(arr.size() <=1)
            return {};

            
        sort(arr.begin(), arr.end());

        int left=0, right = arr.size()-1, diff = INT_MAX;
        int maxAbsDiff = INT_MIN;

        pair<int, int> idx;
        
        while(left < right){
           int sum = arr[left]+arr[right];
           int currDiff = abs(sum - target);
            if(currDiff < diff || (currDiff == diff && abs(arr[right]- arr[left])> maxAbsDiff)){
                diff= currDiff;
                idx={left, right};
                maxAbsDiff = abs(arr[right]- arr[left]);
            }
            if(sum < target){
                left++;
            }else{
                right--;
            }
        }
        return {arr[idx.first], arr[idx.second]};
            
    }
};