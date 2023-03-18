// preorder
class Solution {
  void preorder(TreeNode *root, vector<int> &ans) {
    if (root == nullptr)
      return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
  }

public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
  }
};

// iterative preorder

class Solution {
  void preorder(TreeNode *root, vector<int> &ans) {
    if (!root)
      return;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *temp = st.top();
      st.pop();
      ans.push_back(temp->val);
      if (temp->right) {
        st.push(temp->right);
      }
      if (temp->left) {
        st.push(temp->left);
      }
    }
  }

public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    preorder(root, ans);
    return ans;
  }
};
