/*
    1. We create an unordered_map to store parent-child relationships for quick traversal.
    2. A BFS traversal is used to map parent nodes and locate the target node.
    3. After finding the target node, another BFS is initiated to spread the fire.
    4. An unordered_map vis ensures nodes are visited only once to prevent redundant processing.
    5. In each BFS level, fire spreads to left, right, and parent nodes.
    6. If fire spreads in a given second, the time counter is incremented.
    7. The function returns the minimum time needed to burn the entire tree.
*/


class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> parentMap;
        Node* tar = nullptr;
        queue<Node*> q;
        
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if (curr->data == target) tar = curr;
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        q.push(tar);
        unordered_map<Node*, bool> vis;
        vis[tar] = true;
        
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
