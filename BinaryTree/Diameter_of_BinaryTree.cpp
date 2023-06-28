// Diameter of Binary Tree

class Solution {
    int dfs(TreeNode *root, int &maxHeight) {
        if (not root) return 0;
        int left = dfs(root->left, maxHeight);
        int right = dfs(root->right, maxHeight);
        if (maxHeight <= left + right) {
            maxHeight = left + right;
        }
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        int maxHeight = 0;
        dfs(root, maxHeight);
        return maxHeight;
    }
};