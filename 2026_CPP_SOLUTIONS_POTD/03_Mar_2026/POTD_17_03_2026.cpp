// Burning Tree Problem

/*
 *    1. We need to calculate the minimum time to burn the entire binary tree.
 *    2. Fire starts from the target node and spreads to its parent and children.
 *    3. To track parent nodes, we build a parent mapping using BFS.
 *    4. Once the target node is found, we simulate fire spreading level by level.
 *    5. A queue is used to process nodes in breadth-first manner.
 *    6. A visited map ensures nodes are not processed multiple times.
 *    7. Time Complexity: O(N), Space Complexity: O(N), where N is the number of nodes.
 */

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = nullptr;
        queue<Node*> q;
        
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->data == target) targetNode = curr;
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        q.push(targetNode);
        unordered_map<Node*, bool> vis;
        vis[targetNode] = true;
        
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            bool fireSpread = false;
            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                if (curr->left && !vis[curr->left]) {
                    q.push(curr->left);
                    vis[curr->left] = true;
                    fireSpread = true;
                }
                if (curr->right && !vis[curr->right]) {
                    q.push(curr->right);
                    vis[curr->right] = true;
                    fireSpread = true;
                }
                if (parentMap[curr] && !vis[parentMap[curr]]) {
                    q.push(parentMap[curr]);
                    vis[parentMap[curr]] = true;
                    fireSpread = true;
                }
            }
            if (fireSpread) time++;
        }
        return time;
    }
};

// Key Points
// 1. BFS is used to build parent mapping.
// 2. Target node is identified during parent mapping.
// 3. Fire spreads simultaneously to parent and children.
// 4. Queue ensures level-order traversal for fire spread.
// 5. Visited map prevents revisiting nodes.
// 6. Time increments only when fire spreads further.
// 7. Overall complexity is linear in number of nodes.
