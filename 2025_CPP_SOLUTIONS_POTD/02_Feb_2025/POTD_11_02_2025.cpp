class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST_util(Node* root,int mn,int mx)
    {
        if(root == NULL)
        {
            return true;
        }
        if(root->data > mn && root->data < mx)
        {
            return (isBST_util(root->left,mn,root->data) && isBST_util(root->right,root->data,mx));
        }
        return false;
    }
    
    
    bool isBST(Node* root) 
    {
        return isBST_util(root,INT_MIN,INT_MAX);
    }
};