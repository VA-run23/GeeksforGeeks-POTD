/*
    1. This code defines a function `countBSTs` that calculates the number of unique Binary Search Trees (BSTs) that can be formed using each element of the input array as the root.
    2. The array `bsts` holds the first few Catalan numbers, which represent the number of unique BSTs that can be formed with `n` nodes.
    3. For each element in the input array `arr`, the code counts how many elements are less than (`l`) and greater than (`g`) the current element.
    4. These counts represent the number of nodes that would go to the left and right subtrees respectively if the current element were the root.
    5. The number of BSTs for that root is calculated as `bsts[l] * bsts[g]`, since the left and right subtrees can be formed independently.
    6. The result for each root is stored in the `bstCount` vector, which is returned at the end.
    7. Time Complexity: O(n^2), due to nested loops; Space Complexity: O(n), for storing the result vector.
*/

class Solution {
  public:
    vector<int> bsts = {1, 1, 2, 5, 14, 42 };
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
    
        int n=arr.size();
        vector<int> bstCount;
        for(int i = 0; i<n; i++){
            int l=0, g=0;
            for(int j = 0;j<n;j++){
                if(arr[i]<arr[j]){
                    g++;
                }
                else if(arr[i]>arr[j]){
                    l++;
                }
            }
            bstCount.push_back(bsts[l]*bsts[g]);
        }
        return bstCount;
    }
};