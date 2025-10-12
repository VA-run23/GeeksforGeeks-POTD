/*
    1. This solution distributes candies in a binary tree so that each node ends up with exactly one candy.
    2. The 'dfs' function recursively calculates the excess or deficit of candies at each node.
    3. For each node, it computes the net balance: 'node->data + left + right - 1', where '-1' accounts for the one candy the node should retain.
    4. The absolute values of left and right balances represent the number of moves needed to transfer candies to or from child nodes.
    5. These moves are accumulated in the 'moves' variable, which is returned as the final answer.
    6. The traversal is post-order (left, right, root), ensuring that child balances are resolved before parent decisions.
    7. Time Complexity: O(n), Space Complexity: O(h), where n = number of nodes and h = height of the tree due to recursion stack.
*/

class Solution {
    int moves;
    public:
    int distCandy(Node* root) {
        // code here
        moves = 0;
        dfs(root);
        return moves;
    }

    private:
    int dfs(Node* node) {
        if (node == nullptr) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        moves += abs(left) + abs(right);
        return node->data + left + right - 1;
    }
};