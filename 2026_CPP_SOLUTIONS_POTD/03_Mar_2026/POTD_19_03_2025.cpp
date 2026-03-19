// Largest BST in a Binary Tree

/*
 *    1. We need to find the largest BST subtree inside a given binary tree.
 *    2. Each node carries information about its subtree: size, min, max, and BST validity.
 *    3. A helper struct `Info` is used to store these details for each recursive call.
 *    4. The recursion checks left and right subtrees and validates BST properties.
 *    5. If both subtrees are BSTs and the current node satisfies BST rules, we update the answer.
 *    6. Otherwise, we take the maximum BST size from left or right subtrees.
 *    7. Time Complexity: O(N), Space Complexity: O(H) where H is tree height.
 */

class Solution {
    struct Info {
        int size;
        int max;
        int min;
        int ans;
        bool isBST;
        
        Info(int size, int max, int min, int ans, bool isBST)
            : size(size), max(max), min(min), ans(ans), isBST(isBST) {}
    };
    
    Info largestBSTUtil(Node* root) {
        if (root == nullptr) {
            return Info(0, INT_MIN, INT_MAX, 0, true);
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return Info(1, root->data, root->data, 1, true);
        }
        
        Info left = largestBSTUtil(root->left);
        Info right = largestBSTUtil(root->right);
        
        Info curr(1 + left.size + right.size, max(root->data, right.max), min(root->data, left.min), 0, false);
        
        if (left.isBST && right.isBST && root->data > left.max && root->data < right.min) {
            curr.min = min(curr.min, left.min);
            curr.max = max(curr.max, right.max);
            curr.ans = curr.size;
            curr.isBST = true;
        } else {
            curr.ans = max(left.ans, right.ans);
        }
        
        return curr;
    }

public:
    int largestBst(Node* root) {
        return largestBSTUtil(root).ans;
    }
};

// Key Points
// 1. Uses a helper struct `Info` to store subtree properties.
// 2. Recursively computes size, min, max, and BST validity.
// 3. Base case handles null and leaf nodes.
// 4. Validates BST property using left.max and right.min.
// 5. Updates answer when subtree is a valid BST.
// 6. Falls back to max of left/right answers if not BST.
// 7. Efficient O(N) solution leveraging post-order traversal.
