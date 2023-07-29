// Lowest Common Ancestor of a Binary Search Tree

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (not root) return nullptr;
        int val = root->val;
        if (p->val < val and q->val < val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > val and q->val > val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};