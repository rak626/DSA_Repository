// Top View Of Binary Tree

vector<int> getTopView(TreeNode<int> *root) {
  vector<int> topView;
  if (not root)
    return topView;
  map<int, int> nodes;
  queue<pair<TreeNode<int> *, int>> todo;
  todo.push({root, 0});
  while (not todo.empty()) {
    TreeNode<int> *temp = todo.front().first;
    int vt = todo.front().second;
    todo.pop();
    if (nodes.find(vt) == nodes.end()) {
      nodes[vt] = temp->val;
    }
    if (temp->left) {
      todo.push({temp->left, vt - 1});
    }
    if (temp->right) {
      todo.push({temp->right, vt + 1});
    }
  }
  for (auto p : nodes) {
    topView.push_back(p.second);
  }
  return topView;
}