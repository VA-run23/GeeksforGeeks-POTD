class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    int findInorderIndex(vector<int> &inorder, int start, int end, int value) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == value)
                return i;
        }
        return -1;
    }

    Node* buildTreeUtil(vector<int> &inorder, vector<int> &preorder, int inorderStart, int inorderEnd, int &preorderIndex) {
        if (inorderStart > inorderEnd)
            return NULL;

        Node* node = new Node(preorder[preorderIndex++]);

        if (inorderStart == inorderEnd)
            return node;

        int inorderIndex = findInorderIndex(inorder, inorderStart, inorderEnd, node->data);

        node->left = buildTreeUtil(inorder, preorder, inorderStart, inorderIndex - 1, preorderIndex);
        node->right = buildTreeUtil(inorder, preorder, inorderIndex + 1, inorderEnd, preorderIndex);

        return node;
    }
    // code here
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int preorderIndex = 0;
        return buildTreeUtil(inorder, preorder, 0, inorder.size() - 1, preorderIndex);
    }
};