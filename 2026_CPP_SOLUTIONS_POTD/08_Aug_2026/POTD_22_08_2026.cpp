
// Number of Turns in Binary Tree

/*
 *    1. The problem asks to count the number of turns in the path between two nodes in a binary tree.
 *    2. First, find the Lowest Common Ancestor (LCA) of the two nodes.
 *    3. From the LCA, compute paths to both target nodes using DFS.
 *    4. Each path is represented as a string of 'L' and 'R' directions.
 *    5. Count turns by checking changes in direction between consecutive steps.
 *    6. If LCA equals one of the nodes, only compute path to the other node.
 *    7. Time Complexity: O(n), Space Complexity: O(h).
 */

class Solution {
  private:
    Node* findLCA(Node* root, int p, int q) {
        if (!root || root->data == p || root->data == q) return root;
        Node* left = findLCA(root->left, p, q);
        Node* right = findLCA(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }

    bool getPath(Node* root, int target, string& path) {
        if (!root) return false;
        if (root->data == target) return true;

        path.push_back('L');
        if (getPath(root->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (getPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }

    int countTurns(const string& path) {
        int turns = 0;
        for (int i = 1; i < path.size(); i++) {
            if (path[i] != path[i - 1]) turns++;
        }
        return turns;
    }

  public:
    int numberOfTurns(Node* root, int p, int q) {
        if (!root || p == q) return -1;

        Node* lca = findLCA(root, p, q);
        if (!lca) return -1;

        if (lca->data == p) {
            string path;
            getPath(lca, q, path);
            int turns = countTurns(path);
            return (turns == 0) ? -1 : turns;
        }
        if (lca->data == q) {
            string path;
            getPath(lca, p, path);
            int turns = countTurns(path);
            return (turns == 0) ? -1 : turns;
        }

        string pathP, pathQ;
        getPath(lca, p, pathP);
        getPath(lca, q, pathQ);

        int turns = countTurns(pathP) + countTurns(pathQ) + 1; 
        return (turns == 0) ? -1 : turns;
    }
};

// Key Points
// 1. Finds LCA of the two nodes.
// 2. Builds path strings from LCA to each node.
// 3. Counts turns by direction changes in path.
// 4. Handles cases where LCA equals one of the nodes.
// 5. Returns -1 if no turns exist.
// 6. Efficient DFS traversal ensures O(n) time.
// 7. Uses O(h) space for recursion stack.