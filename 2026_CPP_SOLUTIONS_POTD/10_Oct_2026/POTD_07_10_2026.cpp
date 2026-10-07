// Max Path Sum Between Two Leaves

/*
 * 1. Problem:
 *    - Given a binary tree, find the maximum path sum between two leaf nodes.
 *
 * 2. Approach:
 *    - Use recursion to compute maximum root-to-leaf path sums.
 *
 * 3. Base case:
 *    - If root == nullptr → return 0.
 *
 * 4. Recursive step:
 *    - Compute leftMax = solve(root->left).
 *    - Compute rightMax = solve(root->right).
 *
 * 5. Leaf node case:
 *    - If both children are null → return root->data.
 *
 * 6. Single child case:
 *    - If only one child exists → return root->data + childMax.
 *
 * 7. Both children case:
 *    - Update global maxSum = max(maxSum, root->data + leftMax + rightMax).
 *    - Return max(root->data + leftMax, root->data + rightMax).
 */

class Solution {
    int maxSum;

    int solve(Node* root) {
        if (root == nullptr) return 0;

        int leftMax = solve(root->left);
        int rightMax = solve(root->right);

        if (root->left == nullptr && root->right == nullptr) {
            return root->data;
        } else if (root->left == nullptr) {
            return root->data + rightMax;
        } else if (root->right == nullptr) {
            return root->data + leftMax;
        } else {
            maxSum = std::max(maxSum, root->data + leftMax + rightMax);
            return std::max(root->data + leftMax, root->data + rightMax);
        }
    }

public:
    int maxPathSum(Node* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum == INT_MIN ? -1 : maxSum;
    }
};

// 🔑 Key Points
// - Recursively compute max root-to-leaf path sums.
// - Leaf nodes return their own value.
// - Single-child nodes return value + child path.
// - Both-child nodes update global maxSum.
// - Answer = global maxSum (max path between two leaves).
// - Handles edge case: tree with only one leaf → return -1.
// - Time complexity: O(n), Space complexity: O(h) recursion stack.