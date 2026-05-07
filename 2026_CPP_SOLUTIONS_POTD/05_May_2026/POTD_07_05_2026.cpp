// Check if Subtree

/*
 *    1. Given two binary trees, determine if one is a subtree of the other.
 *    2. A subtree means the second tree appears within the first with identical structure and values.
 *    3. The algorithm recursively checks for equality of nodes and their children.
 *    4. If a match is found, it verifies the entire subtree structure.
 *    5. If no match is found, it continues searching in the left and right subtrees.
 *    6. The solution uses recursion to traverse and compare nodes.
 *    7. Time Complexity: O(n * m), Space Complexity: O(h) where n = nodes in root1, m = nodes in root2, h = height of tree.
 */

class Solution {
  public:
    bool checktree(Node* root1,Node* root2,bool &ans) {
        
       if (!root1 && !root2) return 1;
       if (!root1 || !root2) return 0;
        bool lefty = false,righty = false;
        if (root1->data == root2->data) {
            lefty = checktree(root1->left,root2->left,ans);
            righty = checktree(root1->right,root2->right,ans);
        }
        return lefty || righty;
    }

    bool iterate(Node* root1, Node* root2,bool &ans) {
        if (!root1 || !root2) return false;
        bool wow = false;
        if (root1->data == root2->data) {
            wow = checktree(root1,root2,ans);
        }
        
        bool lefty = iterate(root1->left,root2,ans);
        bool righty = iterate(root1->right,root2,ans);
        if (wow) return 1;
        return lefty || righty;
    }

    bool isSubTree(Node *root1, Node *root2) {
        // code here
        bool ans = 0;
        ans = iterate(root1,root2,ans);
        return ans;
    }
};

// Key Points
// 1. The function checks if root2 is a subtree of root1.
// 2. Uses recursion to traverse both trees.
// 3. Compares node values and structure simultaneously.
// 4. Returns true if an identical subtree is found.
// 5. Handles null cases carefully to avoid segmentation faults.
// 6. Uses helper functions for clarity (checktree and iterate).
// 7. Complexity can be optimized further using hashing or serialization.