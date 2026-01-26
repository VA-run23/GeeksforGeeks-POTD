/*
    1. The function permuteDist initializes helper structures and calls backtrack to generate all permutations.
    2. backtrack builds permutations recursively by adding unused elements into a temporary vector 'temp'.
    3. The 'used' boolean array ensures that each element of 'arr' is included only once per permutation.
    4. When 'temp' reaches the same size as 'arr', it represents a complete permutation and is added to 'ans'.
    5. After exploring one choice, the algorithm backtracks: removes the last element and marks it unused to explore other possibilities.
    6. This recursive exploration guarantees that all possible arrangements of the input array are generated.
    7. Time Complexity: O(n * n!) because there are n! permutations and copying each takes O(n); Space Complexity: O(n) for recursion stack and 'used' array (excluding output storage).
*/

class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(arr.size(), false);
        
        backtrack(arr, temp, used, ans);
        return ans;
    }
    
private:
    void backtrack(vector<int>& arr, vector<int>& temp, vector<bool>& used, vector<vector<int>>& ans) {
        if (temp.size() == arr.size()) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                temp.push_back(arr[i]);
                backtrack(arr, temp, used, ans);
                temp.pop_back();
                used[i] = false;
            }
        }
    }
};