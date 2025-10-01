/*
    1. This code generates all unique permutations of a given integer array using recursion and backtracking.
    2. The 'pushing' function recursively builds permutations by tracking visited elements and storing complete permutations in a set.
    3. The 'vis' vector ensures that each element is used only once per permutation.
    4. The 'set<vector<int>> s' automatically removes duplicate permutations due to its unique property.
    5. Once all permutations are generated, they are transferred from the set to a vector for the final output.
    6. Time Complexity: O(n! × n), where n is the size of the array — n! permutations and each takes O(n) time to construct.
    7. Space Complexity: O(n! × n) for storing permutations + O(n) for recursion stack and visited array.
*/

class Solution {
  public:
  
    void pushing(vector<int> vis, vector<int> arr, set<vector<int>> &s,vector<int> temp) {
        int n = arr.size();
        if (temp.size() == n) {
            s.insert(temp);
            return;
        }
        
        for (int i =0; i < n;i++) {
            if (vis[i] == 0) {
                vis[i] = 1;
                temp.push_back(arr[i]);
                pushing(vis,arr,s,temp);
                temp.pop_back();
                vis[i] = 0;    
            }
            
            
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        set<vector<int>> st;
        vector<vector<int>> v;
        int n = arr.size();
        vector<int> temp;
        vector<int> vis(n,0);
        pushing(vis,arr,st,temp);
        for (auto i:st) v.push_back(i);
        return v;
        
    }
};