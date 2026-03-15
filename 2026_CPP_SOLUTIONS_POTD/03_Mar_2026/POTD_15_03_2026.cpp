// Vertical Order Traversal of Binary Tree

/*
 *    1. Perform a level-order traversal using a queue.
 *    2. Track each node’s horizontal distance (HD) from the root.
 *    3. Store nodes in a map keyed by HD values.
 *    4. Maintain the minimum HD to normalize indices later.
 *    5. Push left child with HD - 1 and right child with HD + 1.
 *    6. Construct the final vector by shifting HDs to non-negative indices.
 *    7. Time Complexity: O(N), Space Complexity: O(N) where N = number of nodes.
 */

class Solution {
public:
    vector<vector<int>> verticalOrder(Node* root) {
        // code here
        queue<pair<Node*, int>> q;
        unordered_map<int, vector<int>> mp;
        int idx = 0;
        q.push({root, 0});
        while (!q.empty()) {
            Node* node = q.front().first;
            int level = q.front().second;
            idx = min(idx, level);
            q.pop();
            mp[level].push_back(node->data);
            if (node->left)
                q.push({node->left, level - 1});
            if (node->right)
                q.push({node->right, level + 1});
        }
        vector<vector<int>> vec(mp.size());
        if (idx < 0)
            idx = -idx;
        for (auto& x : mp) {
            for (auto& y : x.second) {
                vec[idx + x.first].push_back(y);
            }
        }
        return vec;
    }
};

// Key Points
// 1. Uses BFS to ensure nodes are processed level by level.
// 2. Horizontal distance (HD) determines vertical grouping.
// 3. Negative HD values are normalized using an offset.
// 4. Map stores nodes grouped by HD.
// 5. Queue ensures traversal order is maintained.
// 6. Result vector size equals number of unique HDs.
// 7. Efficient solution with O(N) time and space complexity.