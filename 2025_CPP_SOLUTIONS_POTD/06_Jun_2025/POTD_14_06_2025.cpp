/*
  1. If the root is null, the tree is symmetric by definition. 
  2. Check if left and right subtrees are mirror images using the helper function. 
  3. If both left and right nodes are null, they are symmetric. 
  4. If only one of them is null, symmetry is broken. 
  5. Check if the current nodes have the same value and their respective subtrees are mirrors. 
  6. Time complexity: O(N), where N is the number of nodes, as each node is visited once. 
  7. Space complexity: O(H), where H is the height of the tree due to recursion stack usage in worst-case scenarios. 
*/

class Solution {
  public:
    bool isSymmetric(Node* root) {
        // Code here
            if (!root) return true;
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(Node* left, Node* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
    }
};