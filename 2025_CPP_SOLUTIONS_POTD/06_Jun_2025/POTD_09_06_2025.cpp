/*
    1. The 'solve' function recursively traverses the BST, storing all node values in 'nodes'
        and identifying leaf nodes to store in 'lvs'.
    2. If a node is 'NULL', the function returns 'false', ensuring proper termination of recursion.
    3. The 'isDeadEnd' function initializes two sets: 'nodes' (to track all nodes) and 'lvs' (to track leaf nodes).
    4. The value '0' is inserted into 'nodes' to handle edge cases where '1' is a leaf node.
    5. The 'solve' function is called to populate 'nodes' and 'lvs' with relevant values from the BST.
    6. The function iterates through 'lvs', checking if both 'leaf - 1' and 'leaf + 1' exist in 'nodes', indicating a dead end.
    7. If a dead end is found, the function returns 'true'; otherwise, it returns 'false'.
*/

class Solution {
  public:
    bool solve(Node* root, unordered_set<int>& nodes, unordered_set<int>& lvs) {
        if (!root) return false;

        nodes.insert(root->data);

        if (!root->left && !root->right) {
            lvs.insert(root->data);
        }

        return solve(root->left, nodes, lvs) || solve(root->right, nodes, lvs);
    }

    bool isDeadEnd(Node* root) {
        // Code here
        unordered_set<int> nodes, lvs;
        nodes.insert(0); 

        solve(root, nodes, lvs);

        for (int leaf : lvs) {
            if (nodes.count(leaf - 1) && nodes.count(leaf + 1)) {
                return true;
            }
        }
        return false;
    }
};
