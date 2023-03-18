// Bottom View Of Binary Tree

vector<int> getBottomView(TreeNode<int> *root) {
  vector<int> bottomView;
  if (not root)
    return bottomView;
  map<int, int> nodes;
  queue<pair<TreeNode<int> *, int>> todo;
  todo.push({root, 0});
  while (not todo.empty()) {
    TreeNode<int> *temp = todo.front().first;
    int vt = todo.front().second;
    todo.pop();
    nodes[vt] = temp->val;
    if (temp->left) {
      todo.push({temp->left, vt - 1});
    }
    if (temp->right) {
      todo.push({temp->right, vt + 1});
    }
  }
  for (auto p : nodes) {
    bottomView.push_back(p.second);
  }
  return bottomView;
}