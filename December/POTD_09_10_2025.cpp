/*
     First Approach Explanation:
   - Uses in-place marking: each element maps to an index (abs(arr[i]) - 1).
   - If the value at that index is already negative, the current element is a duplicate.
   - Otherwise, flip the sign at that index to mark it visited.
   - Time complexity: O(n), Space complexity: O(1).
   - Efficient but works only when array values are guaranteed in [1..n].
   - Ensures duplicates are collected only once.
   - Optimal when constraints allow in-place modifications.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++) {
            int idx = abs(arr[i]) - 1;
            if(arr[idx] < 0) ans.push_back(abs(arr[i]));
            else arr[idx] = -arr[idx];
        }
        return ans;
    }
};

/*
     Second Approach Explanation:
   - Uses an unordered_map to track occurrences of each element.
   - For each element, check if it already exists in the map.
   - If yes, push it into the answer vector as a duplicate.
   - Otherwise, mark its presence in the map.
   - Time complexity: O(n), Space complexity: O(n).
   - Works for arbitrary ranges of numbers, not just [1..n].
   - Easier to implement but consumes extra memory.
   - Ensures duplicates are collected only once.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = arr.size();
        for(int i : arr){
            if(mp[i]) ans.push_back(i);
            else mp[i] = 1;
        }
        return ans;
    }
};
