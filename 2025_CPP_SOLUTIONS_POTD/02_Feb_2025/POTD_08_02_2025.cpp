class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if (!root) return ans;

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->data);
            return ans;
        }


        if (root->left) {
            ans.push_back(root->data);
            Node* cur = root->left;
            while (cur) {
                if (cur->left || cur->right) ans.push_back(cur->data);
                if (cur->left) cur = cur->left;
                else cur = cur->right;
            }
        } else {
            ans.push_back(root->data); 
        }

        vector<int> leaves;
        function<void(Node*)> getLeaves = [&](Node* node) {
            if (!node) return;
            getLeaves(node->left);
            if (!node->left && !node->right) leaves.push_back(node->data);
            getLeaves(node->right);
        };
        getLeaves(root);
        ans.insert(ans.end(), leaves.begin(), leaves.end());

       
        vector<int> right;
        if (root->right) {
            Node* cur = root->right;
            while (cur) {
                if (cur->left || cur->right) right.push_back(cur->data);
                if (cur->right) cur = cur->right;
                else cur = cur->left;
            }
        }
        reverse(right.begin(), right.end());
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};
