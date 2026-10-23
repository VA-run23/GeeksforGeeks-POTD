// Count Pairs Violating BST Property

/*
 *    1. The problem asks to count pairs of nodes that violate the BST property.
 *    2. Perform a reverse inorder traversal (right → root → left).
 *    3. Maintain a sorted list of elements visited so far.
 *    4. For each node, find how many previously visited elements are smaller than the current node value.
 *    5. Use lower_bound() to locate the insertion position in the sorted list.
 *    6. The insertion position gives the number of violating pairs contributed by the current node.
 *    7. Time Complexity: O(n²) in worst case due to vector insertion, Space Complexity: O(n).
 */

/* BST Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    vector<int> elements;
    long long pairs = 0;

    void dfs(Node* root) {
        if (!root)
            return;

        dfs(root->right);

        auto it = lower_bound(elements.begin(), elements.end(), root->data);
        int pos = it - elements.begin();

        pairs += pos;
        elements.insert(it, root->data);

        dfs(root->left);
    }

public:
    int pairsViolatingBST(Node *root) {
        elements.clear();
        pairs = 0;

        dfs(root);

        return (int)pairs;
    }
};

// Key Points
// 1. Uses reverse inorder traversal.
// 2. Maintains a sorted list of processed node values.
// 3. lower_bound finds insertion position efficiently.
// 4. Position index equals count of smaller processed elements.
// 5. Each such element contributes to a BST violation pair.
// 6. Stores answer in a global long long variable.
// 7. Uses O(n) extra space for storing node values.