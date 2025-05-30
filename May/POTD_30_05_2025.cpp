/* 
    1. Initialize 'mx' with -1 to store the maximum value less than or equal to 'k'. 
    2. Define 'helper' function to recursively traverse the BST based on 'k'. 
    3. If 'root' is NULL, return (base case for recursion). 
    4. If 'root->data' is less than or equal to 'k', update 'mx' and move right. 
    5. Otherwise, move left (smaller values might be present there). 
    6. Call 'helper' inside 'findMaxFork' to start traversal from 'root'. 
    7. Return 'mx', which holds the greatest number ≤ 'k' in the BST. 
*/


class Solution {
public:
    int mx = -1;

    void helper(Node* root, int k) {
        if (root == NULL) return;

        if (root->data <= k) {
            mx = root->data;
            helper(root->right, k);
        } else {
            helper(root->left, k);
        }
    }

    int findMaxFork(Node* root, int k) {
        // code here
        helper(root, k);
        return mx;
    }
};