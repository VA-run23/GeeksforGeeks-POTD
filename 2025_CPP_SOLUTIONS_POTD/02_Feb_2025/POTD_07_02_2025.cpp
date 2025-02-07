class Solution {
  public:
  vector<int>in;
    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        // Your code here
        if(root != NULL){
            inOrder(root->left);
            in.push_back(root->data);
            inOrder(root->right);
            
        }
        return in;
    }
};