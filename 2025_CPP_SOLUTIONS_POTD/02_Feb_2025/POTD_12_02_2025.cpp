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

    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here
        inorder(root, k);
        return result;
    }
};