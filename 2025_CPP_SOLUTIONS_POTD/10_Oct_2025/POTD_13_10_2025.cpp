/*
   1. This code solves the problem of finding the maximum sum of non-adjacent nodes in a binary tree.
   2. The 'solve' function returns a pair: {include, exclude}, where:
      - include = max sum including current node (excluding its children),
      - exclude = max sum excluding current node (children may be included or excluded).
   3. It uses post-order traversal to compute values for left and right subtrees before processing the current node.
   4. For each node, 'include = node->data + left.exclude + right.exclude'.
   5. 'exclude = max(left.include, left.exclude) + max(right.include, right.exclude)'.
   6. The final answer is the maximum of include and exclude for the root node.
   7. Time Complexity: O(n), Space Complexity: O(h), where n = number of nodes, h = height of tree (due to recursion stack).
*/

class Solution {
  public:
  pair<int,int>solve(Node* root){
        if(!root) return make_pair(0,0);
        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);
        pair<int,int>ans;
        ans.first = root->data + left.second + right.second;
        ans.second = max(left.first,left.second) + max(right.first,right.second);
        return ans;
    }
    int getMaxSum(Node *root) {
        // code here
        pair<int,int>ans;
        ans = solve(root);
        return max(ans.first,ans.second);
    }
};