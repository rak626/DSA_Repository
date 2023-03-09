// Search in a Binary Search Tree

class Solution {
public:
  TreeNode *searchBST(TreeNode *root, int val) {
    while (root and root->val != val) {
      root = root->val < val ? root->right : root->left;
    }
    return root;
  }
};