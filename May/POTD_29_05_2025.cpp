/* 
    1. If the current node is NULL, return as there's nothing to process.
    2. Accumulate the sum of values along the current path.
    3. If the node is a leaf (no children), store the (length, sum) pair in the priority queue.
    4. Recursively call helper for the left child, increasing length by 1.
    5. Recursively call helper for the right child, increasing length by 1.
    6. The priority queue stores multiple paths; the longest path’s sum is returned.
    7. This method ensures that if multiple paths have the same length, the one with the maximum sum is selected.
*/

class Solution {
  public:
    priority_queue<pair<int, int>> ps;
    
    int sumOfLongRootToLeafPath(Node *root) {
        // code here  
        helper(root, 0, 0);
        return ps.top().second;
    }

  private:
    void helper(Node* root, int len, int sum) {
        if (root == NULL) return;
        sum += root->data;
        if (!root->left && !root->right) {
            ps.push({len, sum});
        }
        helper(root->left, len + 1, sum);
        helper(root->right, len + 1, sum);
    }
};
