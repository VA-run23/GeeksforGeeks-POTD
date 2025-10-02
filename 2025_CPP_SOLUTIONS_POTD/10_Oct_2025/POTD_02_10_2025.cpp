/*
    1. This code finds all unique combinations of k numbers (from 1 to 9) that sum up to n using backtracking.
    2. The 'combinationSum' function initializes the result container and starts the recursive search from number 1.
    3. The 'backtrack' function explores each number from 'start' to 9, trying to build valid combinations.
    4. If both 'k == 0' and 'target == 0', a valid combination is found and added to the result.
    5. If 'k == 0' or 'target <= 0', the current path is invalid and recursion stops.
    6. The loop adds the current number to the combination, recurses with updated parameters, and then backtracks.
    7. Time Complexity: O(C(9, k)) — bounded by combinations of 9 choose k; Space Complexity: O(k) — due to recursion depth and current combination storage.
*/

class Solution {
  public:
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, k, n, current, result);
        return result;
    }
  private:
    void backtrack(int start, int k, int target, 
       vector<int>& current, vector<vector<int>>& result) {
        if (k == 0 && target == 0) {
            result.push_back(current);
            return;
        }
        if (k == 0 || target <= 0) return;
        for (int i = start; i <= 9; i++) {
            current.push_back(i);
            backtrack(i + 1, k - 1, target - i, current, result);
            current.pop_back();
        }
    }
};