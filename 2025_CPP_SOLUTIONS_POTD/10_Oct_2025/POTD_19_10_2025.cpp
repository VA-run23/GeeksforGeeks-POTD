/*
    1. This code finds the k values in a Binary Search Tree (BST) that are closest to a given target using a max-heap.
    2. The helper function performs a full traversal of the BST, pushing (absolute difference, value) pairs into the heap.
    3. If the heap size exceeds k, the farthest value (top of max-heap) is removed to maintain only the k closest values.
    4. The priority_queue stores pairs so that the largest difference is always at the top, enabling efficient pruning.
    5. After traversal, the heap contains the k closest values, which are extracted and stored in the result vector.
    6. The result vector is returned unsorted; sorting can be added if required by the problem constraints.
    7. Time Complexity: O(n log k), Space Complexity: O(k) — where n is the number of nodes in the BST.
*/

class Solution {
public:
    void helper(Node* root, int target, int k, priority_queue<pair<int, int>> &mh) {
        if (!root) return;

        int diff = abs(root->data - target);
        mh.push({diff, root->data});

        if (mh.size() > k) {
            mh.pop();
        }

        helper(root->left, target, k, mh);
        helper(root->right, target, k, mh);
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
        priority_queue<pair<int, int>> mh;
        helper(root, target, k, mh);

        vector<int> sol;
        while (!mh.empty()) {
            sol.push_back(mh.top().second);
            mh.pop();
        }

        return sol;
    }
};