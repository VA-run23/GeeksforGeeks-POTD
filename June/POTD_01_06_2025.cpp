/*
    1. Extract the size of the matrix 'mat1' and define an unordered_set to store elements of 'mat2'.
    2. Traverse 'mat2' row by row and insert each element into the set for quick lookup.
    3. Initialize a variable 'count' to track the number of valid pairs.
    4. Iterate through each element in 'mat1' to check for its complement in 'mat2'.
    5. If an element from 'mat1' has a corresponding complement in the set (i.e., 'x - num' exists), increment 'count'.
    6. Continue checking all elements of 'mat1' to ensure all possible pairs are counted.
    7. Finally, return the count of pairs whose sum equals the given target 'x'.
*/

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n = mat1.size();
        unordered_set<int> elem;

        for (const auto& row : mat2) {
            for (int num : row) {
                elem.insert(num);
            }
        }

        int count = 0;
        for (const auto& row : mat1) {
            for (int num : row) {
                if (elem.count(x - num)) {
                    count++;
                }
            }
        }

        return count;
    }
};