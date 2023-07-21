// Lowest Common Ancestor of a Binary Tree

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (not root) return nullptr;
        if (root == p or root == q) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (!left) {
            return right;
        } else if (!right) {
            return left;
        } else {
            return root;
        }
    }
};