// Distribute Candies in a Binary Tree

/*
 *    1. Each node has some candies, and we want to balance them.
 *    2. A node should end up with exactly one candy.
 *    3. Extra candies can be moved to parent or child nodes.
 *    4. Each move transfers one candy between adjacent nodes.
 *    5. We count the total number of moves required.
 *    6. DFS helps calculate surplus/deficit at each node.
 *    7. Time Complexity: O(n), Space Complexity: O(h) where h is tree height.
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
}

// Key Points
// 1. Each node must end with exactly one candy.
// 2. Surplus candies are passed upward or downward.
// 3. Deficit is compensated by moves from neighbors.
// 4. DFS computes balance recursively for each subtree.
// 5. Moves are accumulated from absolute surplus/deficit.
// 6. Efficient solution with linear time complexity.
// 7. Space depends on recursion depth (tree height).
