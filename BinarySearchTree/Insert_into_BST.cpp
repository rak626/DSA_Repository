// Insert into a Binary Search Tree

class Solution {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (not root) return new TreeNode(val);
        TreeNode *cur = root;
        while (true) {
            if (val < cur->val) {
                if (cur->left) {
                    cur = cur->left;
                } else {
                    cur->left = new TreeNode(val);
                    break;
                }
            } else {
                if (cur->right) {
                    cur = cur->right;
                } else {
                    cur->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};