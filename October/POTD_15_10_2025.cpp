/*
1. This code finds the k-th smallest element in a Binary Search Tree (BST) using an inorder traversal.
2. Inorder traversal of a BST yields elements in sorted (ascending) order, so the k-th visited node is the k-th smallest.
3. The 'inorder' function recursively traverses the left subtree, visits the current node, and then the right subtree.
4. A counter 'count' tracks how many nodes have been visited; when 'count == k', the current node's value is stored in 'result'.
5. The traversal stops early once the k-th node is found, avoiding unnecessary recursion.
6. Time Complexity: O(n) in the worst case (visiting all nodes); O(k) in best case if early termination occurs.
7. Space Complexity: O(h) where h is the height of the tree due to recursion stack (O(log n) for balanced BST, O(n) for skewed).
*/

class Solution {
  public:
    int count = 0;
    int result = -1;

    void inorder(Node* root, int k) {
        if (root == NULL) return;
        inorder(root->left, k);
        count++;
        if (count == k) {
            result = root->data;
            return; 
        }
        inorder(root->right, k);
    }

    int kthSmallest(Node *root, int k) {
        // add code here
        inorder(root, k);
        return result;
    }
};