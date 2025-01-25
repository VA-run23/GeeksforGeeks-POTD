class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int total = accumulate(arr.begin(), arr.end(), 0);
        int lSum = 0;
        for(int i = 0; i<arr.size(); i++){
            total-=arr[i];

            if(lSum ==  total){
                return i;
            }
            lSum +=arr[i];
        }
        return -1;
    }
};
