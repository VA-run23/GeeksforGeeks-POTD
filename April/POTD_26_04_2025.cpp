/*
    1. The isCompleteTree function checks if a binary tree satisfies the completeness property by performing a level-order traversal using a queue. If any node has a missing child, the subsequent nodes must not have any children.
    2. The isMaxHeap function ensures the binary tree satisfies the max-heap property by recursively verifying that each node's value is greater than or equal to its children's values.
    3. The isHeap function combines the checks for completeness (isCompleteTree) and max-heap property (isMaxHeap) to determine if the given binary tree is a heap.
    4. The level-order traversal in isCompleteTree has a time complexity of O(n) since every node is visited once and uses a queue, resulting in a space complexity of O(n) for storage.
    5. The isMaxHeap function recursively traverses the tree, leading to a time complexity of O(n) and a space complexity of O(h), where h is the height of the tree (due to the recursion stack).
    6. Overall, the isHeap function ensures the binary tree satisfies both properties with a time complexity of O(n) and space complexity of O(n) in the worst case (dominated by level-order traversal).
    7. This approach efficiently checks the required properties for determining whether a binary tree is a valid heap while leveraging common traversal techniques.
*/

bool isCompleteTree(Node* root) {
    if (!root) return true;

    queue<Node*> q;
    q.push(root);

    bool flag = false; 
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (current->left) {
            if (flag) return false; 
            q.push(current->left);
        } else {
            flag = true;
        }

        if (current->right) {
            if (flag) return false; 
            q.push(current->right);
        } else {
            flag = true;
        }
    }
    return true;
}

bool isMaxHeap(Node* root) {
    if (!root) return true;

    if (!root->left && !root->right) {
        return true;
    }

    if (!root->right) {
        return (root->data >= root->left->data) && isMaxHeap(root->left);
    }


    return (root->data >= root->left->data && root->data >= root->right->data) &&
           isMaxHeap(root->left) && isMaxHeap(root->right);
}

class Solution {
  public:
    bool isHeap(Node* tree) {
        // code here
        return isCompleteTree(tree) && isMaxHeap(tree);        
    }
};