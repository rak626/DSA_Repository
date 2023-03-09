// Check for Balanced Binary Tree

class Solution {
  int dfs(TreeNode *root) {
    if (not root)
      return 0;
    int left = dfs(root->left);
    if (left == -1)
      return -1;
    int right = dfs(root->right);
    if (right == -1)
      return -1;
    if (abs(left - right) > 1)
      return -1;
    return 1 + max(left, right);
  }

public:
  bool isBalanced(TreeNode *root) { return dfs(root) != -1; }
};