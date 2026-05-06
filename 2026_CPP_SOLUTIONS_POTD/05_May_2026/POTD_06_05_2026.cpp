// Size of Binary Tree

/*
 *    1. The problem requires finding the total number of nodes in a binary tree.
 *    2. Each node contributes exactly one to the size of the tree.
 *    3. A recursive traversal can be used to visit all nodes.
 *    4. Inorder traversal ensures every node is counted once.
 *    5. A global counter is incremented for each node encountered.
 *    6. The final answer is returned after traversal completes.
 *    7. Time Complexity: O(N), Space Complexity: O(H) where H is tree height.
 */

class Solution {
public:
    int ans;
    void solve(Node* root) {
        if (!root) {
            return;
        }
        solve(root->left);
        ans++;
        solve(root->right);
    }
    int getSize(Node* root) {
        // code here
        ans = 0;
        solve(root);
        return ans;
    }
};

// Key Points
// 1. Recursive traversal is used to count nodes.
// 2. Inorder traversal ensures all nodes are visited.
// 3. Global counter tracks the size of the tree.
// 4. Base case handles null nodes safely.
// 5. Works for skewed and balanced trees alike.
// 6. Time complexity is linear in number of nodes.
// 7. Space complexity depends on recursion depth (tree height).