/*
    1. This code performs a postorder traversal (Left → Right → Root) of a binary tree using recursion.
    2. The 'traverse' function is a helper that recursively visits the left and right subtrees before processing the current node.
    3. The base case checks if the current node is NULL, in which case it returns immediately.
    4. After visiting both children, the node's data is added to the result vector 'ans'.
    5. The 'postOrder' function initializes the result vector and calls 'traverse' with the root node.
    6. Once traversal is complete, it returns the filled vector containing the postorder sequence.
    7. Time Complexity: O(n), where n is the number of nodes; Space Complexity: O(h), where h is the height of the tree due to recursion stack.
*/

class Solution {
  public:
    void traverse(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        traverse(root->left, ans);
        traverse(root->right, ans);
        ans.push_back(root->data);
    }

    vector<int> postOrder(Node* root) {
        // code here
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};