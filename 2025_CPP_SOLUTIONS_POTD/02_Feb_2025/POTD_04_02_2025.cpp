class Solution {
  public:
    int diameter(Node* root) {
        // Your code here
        int height = 0;
        return dUtil(root, height);
    }

  private:
    int dUtil(Node* root, int& height) {
        if (root == NULL) {
            height = 0;
            return 0;
        }

        int lH = 0, rH = 0;
        int lDia = dUtil(root->left, lH);
        int rDiameter = dUtil(root->right, rH);

        height = max(lH, rH) + 1;
        int rootDia = lH + rH;

        return max(rootDia, max(lDia, rDiameter));
    }
};