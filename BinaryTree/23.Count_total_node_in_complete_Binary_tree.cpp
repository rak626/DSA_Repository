// Count total Nodes in a COMPLETE Binary Tree

class Solution {
    int findLeftHeight(TreeNode *root) {
        int cnt = 0;
        while (root) {
            root = root->left;
            cnt++;
        }
        return cnt;
    }
    int findRightHeight(TreeNode *root) {
        int cnt = 0;
        while (root) {
            root = root->right;
            cnt++;
        }
        return cnt;
    }

public:
    int countNodes(TreeNode *root) {
        if (not root) return 0;
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);

        if (leftHeight == rightHeight) {
            return pow(2, leftHeight) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};