// Minimum Absolute Difference in BST

/*
 *    1. The problem asks to find the minimum absolute difference between values of any two nodes in a BST.
 *    2. Key property: Inorder traversal of BST gives sorted values.
 *    3. Perform inorder traversal and store node values in a vector.
 *    4. Compute differences between consecutive elements in the sorted vector.
 *    5. Track the minimum difference across all consecutive pairs.
 *    6. Return the minimum difference.
 *    7. Time Complexity: O(n), Space Complexity: O(n).
 */

/* Binary Tree Node Structure
class Node {
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> v;

    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }

    int absDiff(Node *root) {
        v.clear();
        inorder(root);

        int mini = INT_MAX;
        for (int i = 0; i < v.size() - 1; i++) {
            int diff = abs(v[i + 1] - v[i]);
            mini = min(mini, diff);
        }
        return mini;
    }
};

// Key Points
// 1. Inorder traversal gives sorted node values.
// 2. Minimum difference must be between consecutive values.
// 3. Store values in vector during traversal.
// 4. Iterate through vector to compute differences.
// 5. Track minimum difference across all pairs.
// 6. Efficient O(n) solution with O(n) space.
// 7. Simple and elegant use of BST property.