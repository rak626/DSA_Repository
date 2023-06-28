// Delete Node in a BST

class Solution {
    TreeNode *findLastRight(TreeNode *root) {
        if (root->right == nullptr) return root;
        return findLastRight(root->right);
    }
    TreeNode *helper(TreeNode *root) {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (not root) return nullptr;
        if (root->val == key) {
            return helper(root);
        }
        TreeNode *cur = root;
        while (cur) {
            if (cur->val > key) {
                if (cur->left and cur->left->val == key) {
                    cur->left = helper(cur->left);
                    break;
                } else {
                    cur = cur->left;
                }
            } else {
                if (cur->right and cur->right->val == key) {
                    cur->right = helper(cur->right);
                    break;
                } else {
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};