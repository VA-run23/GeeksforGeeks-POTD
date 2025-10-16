/*
    1. This function recursively removes nodes from a Binary Search Tree (BST) whose values lie outside the range [l, r].
    2. If the current node is null, it returns null — base case for recursion.
    3. If the node's value is less than l, the entire left subtree is discarded, and recursion continues on the right.
    4. If the node's value is greater than r, the entire right subtree is discarded, and recursion continues on the left.
    5. If the node's value lies within [l, r], both left and right subtrees are recursively pruned.
    6. The function returns the root of the modified BST that contains only values within the specified range.
    7. Time Complexity: O(n), Space Complexity: O(h), where n = number of nodes, h = height of the tree (O(log n) for balanced, O(n) for skewed).
*/

class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        if (root == nullptr)
            return nullptr;

        if (root->data < l)
            return removekeys(root->right, l, r);

        if (root->data > r)
            return removekeys(root->left, l, r);

        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);

        return root;
    }
};