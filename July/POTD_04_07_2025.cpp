/*
    1. This function counts the number of subarrays with at most K distinct integers using a sliding window technique.
    2. 'mp' is a hash map that tracks the frequency of each element in the current window.
    3. The window is defined by pointers 'l' (left) and 'r' (right); we expand 'r' to include new elements.
    4. If the number of distinct elements exceeds K, we shrink the window from the left until it's valid.
    5. For each valid window, the count of subarrays ending at 'r' is '(r - l + 1)' and is added to 'ans'.
    6. The loop continues until we've processed all elements, and the final answer is returned.
    7. Time Complexity: O(n), because each element is added and removed from the map at most once; Space Complexity: O(k), for storing up to K distinct elements.
*/

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int l = 0, r = 0, n = arr.size(), ans = 0;
        while (r < n){
            mp[arr[r]]++;
            while (mp.size() > k){
                mp[arr[l]]--;
                if (mp[arr[l]] == 0) mp.erase(arr[l]);
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
};
