/*
    1. This function checks if the array can be split into at least one subsequence of length ≥ k with equal frequencies and consecutive values.
    2. It first counts the frequency of each element using a map (O(n) time).
    3. Then it iterates through the sorted map entries to detect consecutive keys with equal frequencies.
    4. If such consecutive pairs are found, it increments a length counter `len`.
    5. If the current pair breaks the pattern, `len` resets to 1.
    6. If at any point `len >= k`, the function returns true.
    7. Time Complexity: O(n log n) due to map insertion; Space Complexity: O(n) for storing frequencies.
*/

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k) {
        // code here
        if(arr.size() < 2){
            return 1;
        }
        map<int,int>mp;
        for(auto&it:arr){
            mp[it]++;
        }
        int a = -1;
        int b = -1;
        int len = 1;
        for(auto&[f,s]:mp){
            if((a != -1) && (f - a == 1) && (s == b)){
                len++;
            }else{
                len = 1;
            }
            
            a = f;
            b = s;
            
            if(len >= k){
                return 1;
            }
        }
        
        return 0;
    }
};