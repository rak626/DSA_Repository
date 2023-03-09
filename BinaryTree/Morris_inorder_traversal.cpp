// morris traversal inorder
class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> inorder;
    if (not root)
      return inorder;
    TreeNode *cur = root;
    while (cur != nullptr) {
      if (cur->left == nullptr) {
        inorder.push_back(cur->val);
        cur = cur->right;
      } else {
        TreeNode *prev = cur->left;
        while (prev->right and prev->right != cur) {
          prev = prev->right;
        }
        if (prev->right == nullptr) {
          prev->right = cur;
          cur = cur->left;
        } else {
          prev->right = nullptr;
          inorder.push_back(cur->val);
          cur = cur->right;
        }
      }
    }
    return inorder;
  }
};