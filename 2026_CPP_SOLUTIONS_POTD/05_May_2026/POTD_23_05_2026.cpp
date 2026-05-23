// Transform to Sum Tree

/*
 *    1. Convert each node’s value to the sum of values of its left and right subtrees.
 *    2. Use recursion to traverse the tree in a post-order manner.
 *    3. Base case: if the node is null, return 0.
 *    4. For leaf nodes, store their value, set data to 0, and return the original value.
 *    5. For internal nodes, compute left and right subtree sums recursively.
 *    6. Update the current node’s data to left + right, return total including original value.
 *    7. Time Complexity: O(n), Space Complexity: O(h) where h is tree height (due to recursion stack).
 */

class Solution {
    public:
    void toSumTree(Node *root) {
        // code here
        if (root == nullptr)
            return;
        helper(root);
    }
    
    int helper(Node* root) {
        if (root == nullptr)
            return 0;
        
        if (root->left == nullptr && root->right == nullptr) {
            int temp = root->data;
            root->data = 0;
            return temp;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        int re = root->data + left + right;
        root->data = left + right;
        
        return re;
    }
};

// Key Points
// 1. Post-order traversal ensures children are processed before parent.
// 2. Leaf nodes are set to 0 since they have no children.
// 3. Each node’s new value is sum of left and right subtree values.
// 4. Original node values are preserved temporarily for computation.
// 5. Recursion stack depth depends on tree height.
// 6. Efficient solution with O(n) time complexity.
// 7. Space complexity is O(h), not O(n), since only recursion stack is used.