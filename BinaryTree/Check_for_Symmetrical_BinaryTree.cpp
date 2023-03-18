// Check for Symmetrical Binary Trees

class Solution {
  bool findIsSymmetric(TreeNode *p, TreeNode *q) {
    if (!p or !q)
      return p == q;
    return p->val == q->val && findIsSymmetric(p->left, q->right) &&
           findIsSymmetric(p->right, q->left);
  }

public:
  bool isSymmetric(TreeNode *root) {
    if (not root)
      return true;
    return findIsSymmetric(root->left, root->right);
  }
};