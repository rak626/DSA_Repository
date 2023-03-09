// inorder
class Solution {
  void inorder(TreeNode *root, vector<int> &ans) {
    if (root == nullptr)
      return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
  }

public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
  }
};

// Iterative Inorder

class Solution {
  void inorder(TreeNode *root, vector<int> &ans) {
    if (root == nullptr)
      return;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    while (1) {
      if (cur) {
        st.push(cur);
        cur = cur->left;
      } else {
        if (st.empty())
          break;
        cur = st.top();
        st.pop();
        ans.push_back(cur->val);
        cur = cur->right;
      }
    }
  }

public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
  }
};