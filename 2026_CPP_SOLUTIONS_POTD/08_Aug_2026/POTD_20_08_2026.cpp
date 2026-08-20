// Maximum Difference Between Node and Ancestor

/*
 *    1. The problem asks to find the maximum difference between a node and any of its ancestors in a binary tree.
 *    2. Use recursion to traverse the tree and compute minimum values in subtrees.
 *    3. For each node, compare its value with the minimum value found in its descendants.
 *    4. Update the global maximum difference whenever a larger difference is found.
 *    5. Base case: return INT_MAX for null nodes, and node->data for leaf nodes.
 *    6. Recursive step: return min(node->data, min(left, right)) to propagate minimum values upward.
 *    7. Time Complexity: O(n), Space Complexity: O(h) where h is tree height.
 */

class Solution {
public:
    int solve(Node* root, int &maxi) {
        if (root == NULL) return INT_MAX;
        if (!root->left && !root->right) return root->data;

        int left = solve(root->left, maxi);
        int right = solve(root->right, maxi);

        int b = min(left, right);
        maxi = max(maxi, root->data - b);

        int mini = min(root->data, b);
        return mini;
    } 

    int maxDiff(Node* root) {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};

// Key Points
// 1. Traverses tree recursively to compute minimum descendant values.
// 2. Updates global maximum difference at each node.
// 3. Base case handles null and leaf nodes.
// 4. Returns minimum value in subtree for ancestor comparison.
// 5. Uses INT_MAX and INT_MIN for initialization.
// 6. Ensures difference is always ancestor - descendant.
// 7. Runs in O(n) time with O(h) space.