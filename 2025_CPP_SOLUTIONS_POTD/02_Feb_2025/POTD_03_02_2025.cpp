class Solution {
  public:
    int tH(Node* root) {
        if(root == NULL) return -1;
        int lh = tH(root->left);
        int rh = tH(root->right);
        return max(lh, rh) + 1;
    }

    // Function to find the height of a binary tree.
    int height(Node* node) {
        // code here
        return tH(node);
    }
};