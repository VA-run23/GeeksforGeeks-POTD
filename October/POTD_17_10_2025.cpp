/*
    1. This code transforms a Binary Search Tree (BST) into a Greater Sum Tree, where each node contains the sum of all nodes greater than itself.
    2. It uses reverse inorder traversal (right → root → left) to visit nodes in descending order, ensuring correct accumulation of greater values.
    3. The `helper` function takes a reference to `sum`, which accumulates the total of previously visited nodes.
    4. For each node, its original value is stored in `temp`, then replaced with the current `sum`, and `sum` is updated by adding `temp`.
    5. The traversal continues recursively, updating each node in-place without using extra space for storage.
    6. Time Complexity: O(n), where n is the number of nodes in the BST, since each node is visited once.
    7. Space Complexity: O(h), where h is the height of the tree, due to recursive call stack in depth-first traversal.
*/

class Solution {
  public:
    void helper(Node* root, int &sum) {
        if (root == nullptr) return;
        helper(root->right, sum);
        int temp = root->data;
        root->data = sum;
        sum += temp;
        helper(root->left, sum);
    }

    void transformTree(Node *root) {
        // code here
        int sum = 0;
        helper(root, sum);
    }
};
