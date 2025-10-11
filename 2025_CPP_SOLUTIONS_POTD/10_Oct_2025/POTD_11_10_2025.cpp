/*
    1. This code finds the maximum path sum in a binary tree, where a path can start and end at any node.
    2. The helper function 'fsh' recursively computes the max gain from left and right subtrees, ignoring negative paths using 'max(0, ...)'.
    3. At each node, it calculates the potential max path sum passing through that node: 'root->data + l + r'.
    4. It updates the global result 'res' if this local sum is greater than the current maximum.
    5. The function returns the maximum gain from either left or right subtree plus the current node's value, to be used by its parent.
    6. 'findMaxSum' initializes 'res' to the smallest integer and triggers the recursive traversal.
    7. Time Complexity: O(N), where N is the number of nodes; Space Complexity: O(H), where H is the height of the tree due to recursion stack.
*/

class Solution {
  public:
    int fsh(Node* root,int& res){
        if(!root)return 0;
        
        int l = max(0,fsh(root->left,res));
        int r = max(0,fsh(root->right,res));
        
        res=max(res,root->data+l+r);
        return max(l+root->data,r+root->data);
        
    }
    int findMaxSum(Node *root) {
        // code here
        int res = INT_MIN;
        fsh(root,res);
        return res;
    }
};