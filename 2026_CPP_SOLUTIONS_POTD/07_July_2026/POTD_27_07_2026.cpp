// Construct a Full Binary Tree from Preorder and Preorder-Mirror

/*
 *    1. The problem asks to construct a full binary tree given:
 *       - Preorder traversal of the tree.
 *       - Preorder traversal of its mirror.
 *    2. A full binary tree means every node has either 0 or 2 children.
 *    3. Approach:
 *       - The first element of preorder is always the root.
 *       - Divide the tree into left and right subtrees using preorder and preorder-mirror.
 *       - Recursively construct left and right subtrees.
 *    4. Use helper function `construct` with parameters:
 *       - `pre` (preorder array), index `i`
 *       - `preMirror` (mirror preorder array), index `j`
 *       - `size` (number of nodes in subtree)
 *    5. Base case: If size == 0 → return nullptr.
 *    6. Recursive case:
 *       - Create root node from `pre[i]`.
 *       - Split size into two halves (since full binary tree).
 *       - Construct left subtree from next elements in preorder and corresponding mirror segment.
 *       - Construct right subtree similarly.
 *    7. Return constructed root.
 *    8. Time Complexity: O(n), Space Complexity: O(n).
 */

class Solution {
  private:
    Node* construct(vector<int> &pre, int i, vector<int> &preMirror, int j, int size) {
        Node *root = new Node(pre[i]);
        int newSize = size / 2;

        if (newSize > 0) {
            root->left = construct(pre, i + 1, preMirror, j + newSize + 1, newSize);
            root->right = construct(pre, i + newSize + 1, preMirror, j + 1, newSize);
        }
        return root;
    }

  public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        int size = pre.size();
        return construct(pre, 0, preMirror, 0, size);
    }
};

// Key Points
// 1. Full binary tree property ensures equal split of nodes.
// 2. Preorder and mirror preorder together uniquely define the tree.
// 3. Root is always pre[i], then recursively build left and right.
// 4. Efficient recursive solution in O(n).