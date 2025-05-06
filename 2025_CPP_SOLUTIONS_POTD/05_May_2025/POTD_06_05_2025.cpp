/*
    1. If the tree is empty, return an empty vector.
    2. Initialize a queue for level-order traversal and store the root node.
    3. Process each level one by one and extract the first node (leftmost).
    4. Push the first node of each level into the result vector.
    5. Add child nodes (left first, then right) to the queue for further processing.
    6. Continue this until all levels are processed, ensuring the left view is captured.
    7. Time Complexity: O(N) (each node is visited once); Space Complexity: O(N) (worst case: storing all nodes in the queue).
*/

class Solution {
    public:
      vector<int> leftView(Node *root) {
          // code here
          if (!root) return {};
          vector<int> ans;
          queue<Node*> q;
          q.push(root);
  
          while (!q.empty()) {
              int size = q.size();
              for (int i = 0; i < size; i++) {
                  Node* node = q.front();
                  q.pop();
  
                  if (i == 0) ans.push_back(node->data);
  
                  if (node->left) q.push(node->left);
                  if (node->right) q.push(node->right);
              }
          }
          return ans;
      }
  };