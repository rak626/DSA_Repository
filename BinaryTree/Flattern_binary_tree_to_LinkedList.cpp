// Flatten Binary Tree to Linked List

class Solution
{
  TreeNode *prev = nullptr;
  void makeFlatten(TreeNode *root)
  {
    if (not root)
      return;
    makeFlatten(root->right);
    makeFlatten(root->left);
    root->right = prev;
    root->left = nullptr;
    prev = root;
  }

public:
  void flatten(TreeNode *root) { makeFlatten(root); }
};

// O(1) space
class Solution
{
public:
  void flatten(TreeNode *root)
  {
    TreeNode *cur = root;
    while (cur)
    {
      if (cur->left)
      {
        TreeNode *prev = cur->left;
        while (prev->right)
        {
          prev = prev->right;
        }
        prev->right = cur->right;
        cur->right = cur->left;
      }
      cur->left = nullptr;
      cur = cur->right;
    }
  }
};