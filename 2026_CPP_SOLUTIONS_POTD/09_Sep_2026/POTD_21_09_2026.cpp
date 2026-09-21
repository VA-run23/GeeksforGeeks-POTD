// Check if All Levels of Two Trees are Anagrams

/*
 *    1. The problem asks to check if two binary trees are level-wise anagrams.
 *    2. Approach:
 *       - Perform level-order traversal (BFS) on both trees simultaneously.
 *       - At each level, collect node values from both trees.
 *       - Compare frequency of values at that level.
 *    3. If frequencies match for all levels → return true.
 *    4. If mismatch at any level → return false.
 *    5. Edge cases:
 *       - Both trees empty → true.
 *       - One empty, other non-empty → false.
 *    6. Time Complexity: O(n + m), Space Complexity: O(n + m).
 */

/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            if (n1 != n2) return false;

            unordered_map<int, int> freq;

            // Process level of tree1
            for (int i = 0; i < n1; i++) {
                Node* node = q1.front();
                q1.pop();

                freq[node->data]++;

                if (node->left) q1.push(node->left);
                if (node->right) q1.push(node->right);
            }

            // Process level of tree2
            for (int i = 0; i < n2; i++) {
                Node* node = q2.front();
                q2.pop();

                if (freq.find(node->data) == freq.end()) return false;

                freq[node->data]--;

                if (freq[node->data] == 0) freq.erase(node->data);

                if (node->left) q2.push(node->left);
                if (node->right) q2.push(node->right);
            }

            if (!freq.empty()) return false;
        }

        return q1.empty() && q2.empty();
    }
};

// Key Points
// 1. BFS ensures level-wise traversal.
// 2. Use frequency map to compare values at each level.
// 3. If counts mismatch → not anagrams.
// 4. Both queues must end empty for equality.
// 5. Handles edge cases of empty trees.
// 6. Efficient O(n+m) solution.
// 7. Elegant use of hash map for level comparison.