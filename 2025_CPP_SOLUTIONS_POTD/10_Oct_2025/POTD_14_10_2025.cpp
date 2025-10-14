/*
    1. This function computes the sum of all node values in a Binary Search Tree (BST) that lie within a given range [l, r].
    2. It uses recursion to traverse the tree efficiently by leveraging BST properties to prune unnecessary branches.
    3. If the current node's value is within the range, it adds it to the sum.
    4. If the node's value is greater than l, it explores the left subtree (which may contain smaller valid values).
    5. If the node's value is less than r, it explores the right subtree (which may contain larger valid values).
    6. This avoids traversing parts of the tree that cannot contain values within the range, improving performance.
    7. Time Complexity: O(n) in worst case (skewed tree), O(k) in best/average case where k = number of nodes in range; Space Complexity: O(h) due to recursion stack, where h = height of the tree.
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        // code here
        if (root == NULL) return 0;
        
        int ans = 0;
        if (root->data >= l && root->data <= r) {
            ans += root->data;
        }
        if (root->data > l) {
            ans += nodeSum(root->left, l, r);
        }
        if (root->data < r) {
            ans += nodeSum(root->right, l, r);
        }
        return ans;
    }
};