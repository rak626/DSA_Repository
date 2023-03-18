/ Kth Smallest Element in a BST

    class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    // morris traversal
    if (not root)
      return -1;
    TreeNode *cur = root;
    // vector<int> inorder;
    int ans = 0;
    int count = 0;
    while (cur) {
      if (cur->left == nullptr) {
        // inorder.push_back(cur->val);
        count++;
        if (count == k)
          ans = cur->val;
        cur = cur->right;
      } else {
        auto prev = cur->left;
        while (prev->right and prev->right != cur) {
          prev = prev->right;
        }
        if (prev->right == nullptr) {
          prev->right = cur;
          cur = cur->left;
        }
        if (prev->right == cur) {
          prev->right = nullptr;
          // inorder.push_back(cur->val);
          count++;
          if (count == k)
            ans = cur->val;
          cur = cur->right;
        }
      }
    }
    // return inorder[k-1];
    return ans;
  }
};