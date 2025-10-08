/*
    1. This code constructs a full binary tree from given preorder and postorder traversals using recursion.
    2. A hashmap 'postIndex' stores the index of each node in postorder for O(1) lookup during tree construction.
    3. The recursive function 'buildTree' uses preorder to pick the current root and postorder to determine subtree boundaries.
    4. It creates a new node from 'pre[preIdx]', then recursively builds left and right subtrees using postorder indices.
    5. The base case handles leaf nodes and ensures recursion stops when bounds are invalid or all nodes are processed.
    6. The 'constructTree' function initializes the hashmap and starts the recursive build from the full range.
    7. Time Complexity: O(n), Space Complexity: O(n) — due to hashmap and recursion stack, where n is the number of nodes.
*/

class Solution {
    unordered_map<int, int> postIndex;
    Node* buildTree(vector<int>& pre, vector<int>& post, int& preIdx, int l, int r) {
        if (preIdx >= pre.size() || l > r) return NULL;
        Node* root = new Node(pre[preIdx++]);
        if (l == r || preIdx >= pre.size()) return root;
        int idx = postIndex[pre[preIdx]];
        root->left = buildTree(pre, post, preIdx, l, idx);
        root->right = buildTree(pre, post, preIdx, idx + 1, r - 1);
        return root;
    }

public:
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        // code here
        int n = pre.size();
        for (int i = 0; i < n; ++i)
            postIndex[post[i]] = i;
        int preIdx = 0;
        return buildTree(pre, post, preIdx, 0, n - 1);
    }
};
