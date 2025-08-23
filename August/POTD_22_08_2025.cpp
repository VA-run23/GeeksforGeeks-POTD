/*
    1. This function computes the median of a 2D matrix by flattening it into a 1D vector.
    2. It iterates through each element of the matrix and pushes it into a new vector 'val'.
    3. The nested loops ensure all elements from every row and column are collected.
    4. The vector 'val' is then sorted in ascending order using the standard sort function.
    5. Since the matrix dimensions are always odd, the median is the middle element of the sorted vector.
    6. The median is accessed using the index: total number of elements divided by 2.
    7. Time Complexity: O(n*m log(n*m)) due to sorting; Space Complexity: O(n*m) for storing all elements.
*/

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int>val;
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++) val.push_back(mat[i][j]);
        sort(val.begin(),val.end());
        return val[(mat.size()*mat[0].size())/2];
    }
};