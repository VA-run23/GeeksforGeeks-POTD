// Vertical Sum of Binary Tree

/*
 *    1. The problem requires calculating the sum of nodes vertically in a binary tree.
 *    2. Each vertical line is identified by its horizontal distance from the root.
 *    3. A map is used to store sums for each horizontal distance.
 *    4. Recursion traverses the tree, updating sums for left and right children.
 *    5. Left child decreases the horizontal distance, right child increases it.
 *    6. Finally, values are collected from the map in order of keys.
 *    7. Time Complexity: O(n), Space Complexity: O(n) where n is the number of nodes.
 */

class Solution {
    public:
    vector<int> verticalSum(Node* root) {
        // code here
        map<int, int> m;
        helper(root, 0, m);
        vector<int> ans;
        for (auto& [key, value]: m) {
            ans.push_back(value);
        }
        
        return ans;
    }
    
    void helper(Node* root, int i, map<int, int>& m) {
        if (!root)
            return;
        
        m[i] += root->data;
        
        helper(root->left, i - 1, m);
        helper(root->right, i + 1, m);
    }
}

// Key Points
// 1. Vertical sum groups nodes by horizontal distance.
// 2. Map ensures ordered storage of sums.
// 3. Recursion simplifies traversal and sum calculation.
// 4. Left subtree decreases index, right increases index.
// 5. Final vector is built from ordered map values.
// 6. Efficient solution with O(n) complexity.
// 7. Works well for balanced and skewed trees alike.