/*
    1. This code defines a class `Solution` with two functions to compute the median of a Binary Search Tree (BST).
    2. `helperFunction` performs an inorder traversal of the BST, storing node values in ascending order into a vector `arr`.
    3. Inorder traversal ensures that the BST elements are collected in sorted order due to BST properties.
    4. `findMedian` uses the sorted vector to compute the median based on the number of nodes `n`.
    5. If `n` is odd, it returns the ((n+1)/2)th element (1-based index), adjusted to 0-based indexing.
    6. If `n` is even, it returns the (n/2)th element (1-based index), also adjusted to 0-based indexing.
    7. Time Complexity: O(n), Space Complexity: O(n) — due to traversal and storage of all node values in the vector.
*/

class Solution {
  public:
    void helperFunction(Node* root, vector<int>& arr) {
        if (root == nullptr) return;
        helperFunction(root->left, arr);
        arr.push_back(root->data);
        helperFunction(root->right, arr);
    }
    
    int findMedian(Node* root) {
        // Code here
        vector<int> arr;
        helperFunction(root, arr);
        int n = arr.size();
        
        if (n % 2 == 1) {
            return arr[(n + 1) / 2 - 1];  
        } else {
            return arr[n / 2 - 1];        
        }
    }
};