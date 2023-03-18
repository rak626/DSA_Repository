// Minimum time taken to BURN the Binary Tree from a Node

/*1. mark parent node of each map
2. take a map vis to track which is already burned
3. traverse each node in left, right and top */

int timeToBurnTree(BinaryTreeNode<int> *root, int start)

    class Solution {
  void markParent(TreeNode *root,
                  unordered_map<TreeNode *, TreeNode *> &parent_track) {
    if (not root)
      return;
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
      TreeNode *node = nodes.front();
      nodes.pop();
      if (node->left) {
        parent_track[node->left] = node;
        nodes.push(node->left);
      }
      if (node->right) {
        parent_track[node->right] = node;
        nodes.push(node->right);
      }
    }
  }

public:
  int timeToBurnTree(TreeNode *root, TreeNode *start) {
    unordered_map<TreeNode *, TreeNode *> parent_track;
    markParent(root, parent_track);

    unordered_map<TreeNode *, bool> vis;
    queue<TreeNode *> nodes;
    nodes.push(start);
    int time = 0;
    while (!nodes.size()) {
      int size = nodes.size();
      bool flag = false;
      for (int i = 0; i < size; i++) {
        TreeNode *cur = nodes.front();
        nodes.pop();
        if (cur->left and !vis[cur->left]) {
          nodes.push(cur);
          vis[cur->left] = true;
          flag = 1;
        }
        if (cur->right and !vis[cur->right]) {
          nodes.push(cur);
          vis[cur->right] = true;
          flag = 1;
        }
        if (parent_track[cur] and !vis[parent_track[cur]]) {
          nodes.push(parent_track[cur]);
          vis[parent_track[cur]] = true;
          flag = 1;
        }
      }
      if (flag)
        time++;
    }
    return time;
  }
};