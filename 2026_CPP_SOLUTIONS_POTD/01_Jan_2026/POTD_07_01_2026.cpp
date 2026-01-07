/*
    1. We use an unordered_map<int,int> 'mp' to store frequencies of elements in the current window of size k.
    2. First, we initialize the map with the first k elements and push the distinct count (mp.size()) into the answer vector.
    3. Then we slide the window one element at a time: remove the outgoing element (decrement its frequency).
    4. If the outgoing element's frequency becomes zero, we erase it from the map to maintain only active elements.
    5. Next, we add the incoming element by incrementing its frequency in the map.
    6. After each slide, we push the current distinct count (mp.size()) into the answer vector.
    7. Time Complexity: O(n) average (since unordered_map operations are O(1) on average); Space Complexity: O(k) for storing frequencies.
*/

// Key Points from earlier queries:
// - Using set<int> alone fails because erasing removes all occurrences of a value, even if duplicates remain.
// - Using multiset<int> alone fails because s.size() counts total elements, not distinct ones.
// - Improvement: unordered_map<int,int> correctly tracks frequencies, ensuring accurate distinct counts in each window.

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> mp;
        int n = arr.size();
        vector<int>ans;
        for(int i = 0; i<k; i++){
            mp[arr[i]]++;
        }
        ans.push_back(mp.size());
        
        for(int i = k;  i<n; i++){
            
            mp[arr[i - k]]--;
            if(mp[arr[i - k]] == 0)mp.erase(arr[i - k]);
            mp[arr[i]]++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};