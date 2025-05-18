/* 
    1. If the root is NULL, return an empty vector.
    2. Use a deque (`dq`) to efficiently process nodes from both ends.
    3. Use a boolean (`LR`) to toggle between left-to-right and right-to-left traversal.
    4. Process each level iteratively, storing elements in a temporary vector (`levelData`).
    5. If `LR` is true, process nodes normally, else process them in reverse.
    6. Toggle `LR` at each level and insert `levelData` into the final answer `ans`.
    7. Time Complexity: O(N) (each node is visited once); Space Complexity: O(N) (deque + result storage).
*/

class Solution {
  public:
    vector<int> findSpiral(Node* root) {


        if (!root) return {};

        vector<int> ans;
        deque<Node*> dq;
        dq.push_back(root);
        bool LR = false;

        while (!dq.empty()) {
            int size = dq.size();
            vector<int> levelData(size);
            
            for (int i = 0; i < size; i++) {
                if (LR) {
                    Node* node = dq.front();
                    dq.pop_front();
                    levelData[i] = node->data;
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } else {
                    Node* node = dq.back();
                    dq.pop_back();
                    levelData[i] = node->data;
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
            }
            LR = !LR; 
            ans.insert(ans.end(), levelData.begin(), levelData.end());
        }
        return ans;
    }
};
