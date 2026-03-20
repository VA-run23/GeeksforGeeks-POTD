// Predecessor and Successor in BST

/*
 *    1. Given a BST and a key, find its predecessor and successor.
 *    2. Predecessor is the largest value smaller than the key.
 *    3. Successor is the smallest value greater than the key.
 *    4. Traverse the BST iteratively to locate potential pre and suc.
 *    5. If key is found, explore left subtree for predecessor and right subtree for successor.
 *    6. Return both nodes as a pair in a vector.
 *    7. Time Complexity: O(h), Space Complexity: O(1), where h = height of BST.
 */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL, *suc = NULL;
        while (root) {
            if (root->data < key) {
                pre = root;
                root = root->right;
            } else if (root->data > key) {
                suc = root;
                root = root->left;
            } else {
                if (root->left) {
                    Node* temp = root->left;
                    while (temp->right) temp = temp->right;
                    pre = temp;
                }
                if (root->right) {
                    Node* temp = root->right;
                    while (temp->left) temp = temp->left;
                    suc = temp;
                }
                break;
            }
        }
        return {pre, suc};
    }
};

// Key Points
// 1. Predecessor is the rightmost node in left subtree.
// 2. Successor is the leftmost node in right subtree.
// 3. Iterative traversal avoids extra recursion stack.
// 4. Works efficiently in balanced BSTs.
// 5. Handles case when key is not present by tracking closest nodes.
// 6. Returns NULL if predecessor or successor doesn’t exist.
// 7. Optimized for O(h) search, better than full traversal O(n).