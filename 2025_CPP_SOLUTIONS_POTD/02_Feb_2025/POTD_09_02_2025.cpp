class Solution {
  public:
    int fsh(Node* root,int& res){
        if(!root)return 0;
        
        int l = max(0,fsh(root->left,res));
        int r = max(0,fsh(root->right,res));
        
        res=max(res,root->data+l+r);
        return max(l+root->data,r+root->data);
        
    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int res = INT_MIN;
        fsh(root,res);
        return res;
    }
};