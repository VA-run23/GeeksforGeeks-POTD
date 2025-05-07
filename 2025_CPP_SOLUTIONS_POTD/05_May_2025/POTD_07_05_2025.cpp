/*
    1. The function findPaths uses recursion to traverse the binary tree.
    2. Each node's value is added to the path vector as the traversal progresses.
    3. When a leaf node is reached (both left and right children are null), the current path is stored in result.
    4. The function explores both left and right subtrees recursively to maintain correct order.
    5. The last inserted node is removed (backtracking) to correctly form other paths.
    6. The Paths function initializes the required vectors and triggers findPaths from the root.
    7. Time Complexity: O(N) (each node is visited once), Space Complexity: O(H) (due to recursion stack, where H is tree height).
*/

class Solution {
  public:
    void findPaths(Node* root, vector<int>& path, vector<vector<int>>& result) {
        if (!root) return;
        
        path.push_back(root->data);
        
        if (!root->left && !root->right) {
            result.push_back(path);
        } else {
            findPaths(root->left, path, result);
            findPaths(root->right, path, result);
        }
        
        path.pop_back();
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> path;
        findPaths(root, path, result);
        return result;
    }
};
