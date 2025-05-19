/*
    1. Initialize predecessor (pre) and successor (suc) as NULL.
    2. Traverse the BST while root is not NULL.
    3. If root’s value is less than the key, update pre and move right.
    4. If root’s value is greater than the key, update suc and move left.
    5. If key matches root, find the largest in left subtree (predecessor).
    6. Find the smallest in right subtree (successor) and break.
    7. Return predecessor and successor as a vector.
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* pre = NULL, *suc = NULL;
        while (root) {
            if (root->data < key) {
                pre = root;
                root = root->right;
            } else if (root->data > key) {
                suc = root;
                root = root->left;
            } else {
                if (root->left) {
                    Node* temp = root->left;
                    while (temp->right) temp = temp->right;
                    pre = temp;
                }
                if (root->right) {
                    Node* temp = root->right;
                    while (temp->left) temp = temp->left;
                    suc = temp;
                }
                break;
            }
        }
        return {pre, suc};
    }
};
