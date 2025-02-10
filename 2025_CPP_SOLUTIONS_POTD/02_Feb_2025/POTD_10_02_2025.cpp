class Solution {
  public:
    int sumK(Node *root, int k) {
        // code here

        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // To handle the case when path sum equals k at the root
        return dfs(root, k, 0, prefixSumCount);
    }

    private:
    int dfs(Node* node, int k, int currentSum, unordered_map<int, int>& prefixSumCount) {
        if (!node) return 0;

        currentSum += node->data;
        int paths = prefixSumCount[currentSum - k];

        prefixSumCount[currentSum]++;
        paths += dfs(node->left, k, currentSum, prefixSumCount);
        paths += dfs(node->right, k, currentSum, prefixSumCount);
        prefixSumCount[currentSum]--;

        return paths;
    }
};
