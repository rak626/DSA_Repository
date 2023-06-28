// Validate Binary Search Tree

class Solution {
    bool isValidBST(TreeNode *root, long minVal, long maxVal) {
        if (not root) return true;
        if (root->val <= minVal or root->val >= maxVal) return false;

        return isValidBST(root->left, minVal, root->val) and
               isValidBST(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};