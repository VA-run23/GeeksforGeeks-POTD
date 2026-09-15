// Leaf Nodes Under Budget

/*
 *    1. The problem asks to count how many leaf nodes can be visited within a given budget k.
 *    2. Each leaf node has a "cost" equal to its depth (level) in the tree.
 *    3. Perform DFS to collect levels of all leaf nodes.
 *    4. Sort the leaf levels to prioritize cheaper leaves first.
 *    5. Greedily pick leaves until the budget is exhausted.
 *    6. Count how many leaves can be visited within budget.
 *    7. Time Complexity: O(n log n), Space Complexity: O(n).
 */

/* Binary Tree Node Structure
class Node {
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    void dfs(Node* root, int level, vector<int>& leaves) {
        if (!root) return;
        if (!root->left && !root->right) {
            leaves.push_back(level);
            return;
        }
        dfs(root->left, level + 1, leaves);
        dfs(root->right, level + 1, leaves);
    }
    
    int getCount(Node* root, int k) {
        vector<int> leaves;
        dfs(root, 1, leaves);
        sort(leaves.begin(), leaves.end());
        
        int count = 0, sum = 0;
        for (int cost : leaves) {
            if (sum + cost <= k) {
                sum += cost;
                count++;
            } else break;
        }
        return count;
    }
};

// Key Points
// 1. DFS collects depths of all leaf nodes.
// 2. Each leaf’s cost = depth level.
// 3. Sort leaves by cost for greedy selection.
// 4. Greedily pick leaves until budget exhausted.
// 5. Count maximum leaves visited within budget.
// 6. Efficient O(n log n) solution.
// 7. Uses O(n) extra space for leaf levels.