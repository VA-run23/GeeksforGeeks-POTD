/*
    1. This function counts the number of subarrays with at most K distinct integers using a sliding window approach.  
    2. Two pointers (l and r) define the current window, and an unordered_map tracks the frequency of elements.  
    3. As we expand the window by moving r, we insert arr[r] into the map and increase its count.  
    4. If the map size (distinct elements) exceeds K, we shrink the window from the left by moving l and updating counts.  
    5. Each valid window contributes (r - l + 1) subarrays ending at r, since all subarrays between l and r are valid.  
    6. The variable ans accumulates the total count of such subarrays across the entire array.  
    7. Time Complexity: O(n) on average (each element processed at most twice); Space Complexity: O(k) for the map.  
*/

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int l = 0, ans = 0;
        unordered_map<int, int> mp;

        for (int r = 0; r < arr.size(); r++) {
            mp[arr[r]]++;

            while (mp.size() > k) {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0) mp.erase(arr[l]);
                l++;
            }

            ans += r - l + 1;
        }

        return ans;
    }
};