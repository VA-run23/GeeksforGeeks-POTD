// Longest Consecutive Path in Binary Tree

/*
 *    1. The problem asks for the longest path in the binary tree
 *       where node values are consecutive integers (parent + 1 = child).
 *    2. Use DFS traversal to explore all paths.
 *    3. Maintain a global variable `longest` to track the maximum length.
 *    4. At each node:
 *       - If node->data == parent + 1 → extend current length.
 *       - Else → reset length to 1.
 *    5. Update `longest` with the maximum length found.
 *    6. Traverse both left and right children recursively.
 *    7. Return -1 if no valid consecutive path longer than 1 exists.
 *    8. Time Complexity: O(n), Space Complexity: O(h) (recursion stack).
 */

class Solution {
  public:
    int longest;

    void traversal(Node* root, int parent, int len) {
        if (!root) return;

        // Extend or reset consecutive sequence
        len = (parent + 1 == root->data) ? (len + 1) : 1;

        // Update longest path
        longest = max(longest, len);

        // Recurse left and right
        traversal(root->left, root->data, len);
        traversal(root->right, root->data, len);
    }

    int longestConsecutive(Node* root) {
        longest = 0;
        traversal(root, -1, 0);
        return (longest == 1) ? -1 : longest;
    }
};

// Key Points
// 1. DFS traversal checks consecutive property at each step.
// 2. `len` tracks current consecutive sequence length.
// 3. `longest` stores global maximum length.
// 4. Reset length when sequence breaks.
// 5. Return -1 if no valid sequence longer than 1 exists.
// 6. Efficient O(n) solution with recursion.