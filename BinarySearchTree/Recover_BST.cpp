// Recover Binary Search Tree

/*step 1 : two collison if swapped nodes are not adjacent
step 2 : one collison if swapped nodes are adjacent*/

class Solution {
  TreeNode *first, *mid, *last, *prev;
  void inorder(TreeNode *root) {
    if (not root)
      return;
    inorder(root->left);
    if (prev and root->val < prev->val) {
      if (first == nullptr) {
        first = prev;
        mid = root;
      } else {
        last = root;
      }
    }
    prev = root;
    inorder(root->right);
  }

public:
  void recoverTree(TreeNode *root) {
    first = mid = last = nullptr;
    prev = new TreeNode(INT_MIN);
    inorder(root);
    if (first and last)
      swap(first->val, last->val);
    else if (first and mid)
      swap(first->val, mid->val);
  }
};

class NodeValue {
public:
  int maxNode, minNode, maxSize;

  NodeValue(int minNode, int maxNode, int maxSize) {
    this->maxNode = maxNode;
    this->minNode = minNode;
    this->maxSize = maxSize;
  }
};