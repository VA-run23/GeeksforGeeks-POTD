/*
    1. Calculate the number of troops 'n' and initialize a vector 'req' to store soldiers needed per troop.
    2. For each troop, compute how many soldiers are needed to make its count divisible by 'k' using: (k - arr[i] % k) % k.
    3. This formula ensures that already lucky troops (where arr[i] % k == 0) get a cost of 0.
    4. Sort the 'req' vector to prioritize troops that need fewer soldiers to become lucky.
    5. Accumulate the smallest ⌈n/2⌉ values from 'req' to get the minimum total soldiers needed.
    6. This assumes we must fix ⌈n/2⌉ troops, regardless of how many are already lucky.
    7. Time Complexity: O(n log n) due to sorting; Space Complexity: O(n) for the 'req' vector.
*/

class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        vector<int> req(n, 0);
        // int x = n/2;
        for(int i = 0; i<n; i++){
            req[i] = abs( k -(arr[i] % k));
            req[i] = (k - arr[i] % k) % k;

        }
        sort(req.begin(), req.end());
        
        int ans = accumulate(req.begin(), req.begin() + (n+1)/2, 0);
        return ans;
    }
};