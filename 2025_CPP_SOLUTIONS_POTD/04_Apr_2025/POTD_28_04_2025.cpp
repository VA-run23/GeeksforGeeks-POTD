/*
    1. The function treeToArray calculates two values for each node: 
    (a) include, which is the sum when the current node is included,
    and (b) exclude, which is the maximum sum when the current node is excluded.
    2. The base case returns {0, 0} for a null node.
    3. Recursively process left and right children to obtain their include/exclude sums.
    4. For include, add the node's value to the excluded sums of left and right children.
    5. For exclude, take the maximum of include/exclude sums from both children.
    6. The public getMaxSum function initiates the calculation and returns the maximum 
    of include or exclude sums for the root node.
    7. Time Complexity: O(n), as each node is visited once. 
    Space Complexity: O(h), where h is the height of the tree, due to recursion stack.
*/

class Solution {
    private:
      pair<int, int> treeToArray(Node* root) {
          if (!root) return {0, 0};
          
          pair<int, int> left = treeToArray(root->left);
          pair<int, int> right = treeToArray(root->right);
          
          int include = root->data + left.second + right.second;
          int exclude = max(left.first, left.second) + max(right.first, right.second);
          return {include, exclude};
      }
  
    public:
      // Function to return the maximum sum of non-adjacent nodes.
      int getMaxSum(Node *root) {
          // code here
          pair<int, int> result = treeToArray(root);
          return max(result.first, result.second); 
      }
  };