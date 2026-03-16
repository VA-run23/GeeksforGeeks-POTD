// K-Sum Paths in Binary Tree

/*
 *    1. We are tasked with finding all paths in a binary tree whose sum equals a given value k.
 *    2. A path can start and end at any node but must follow parent-child connections.
 *    3. We use prefix sum technique to efficiently track cumulative sums along paths.
 *    4. An unordered_map stores counts of prefix sums encountered during DFS traversal.
 *    5. At each node, we check if (currSum - k) exists in the map to count valid paths.
 *    6. We increment and decrement prefix sum counts during recursion to maintain correctness.
 *    7. Time Complexity: O(N), Space Complexity: O(N), where N is the number of nodes.
 */

class Solution {
  public:
    int countAllPaths(Node *root, int k) {
        // code here
        unordered_map<int, int> pSumCount;
        pSumCount[0] = 1; 
        return dfs(root, k, 0, pSumCount);
    }

    private:
    int dfs(Node* node, int k, int currSum, unordered_map<int, int>& pSumCount) {
        if (!node) return 0;

        currSum += node->data;
        int paths = pSumCount[currSum - k];

        pSumCount[currSum]++;
        paths += dfs(node->left, k, currSum, pSumCount);
        paths += dfs(node->right, k, currSum, pSumCount);
        pSumCount[currSum]--;

        return paths;
    }
};

// Key Points
// 1. Prefix sum technique avoids recomputation of path sums.
// 2. DFS ensures all possible paths are explored.
// 3. The unordered_map tracks frequency of prefix sums.
// 4. Backtracking (decrementing map count) prevents incorrect path counts.
// 5. Works for paths starting at any node, not just root.
// 6. Efficient compared to brute force path enumeration.
// 7. Handles both positive and negative node values.
