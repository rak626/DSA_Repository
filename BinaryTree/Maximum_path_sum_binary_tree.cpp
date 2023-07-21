// Maximum Path Sum in Binary Tree

class Solution {
    int dfs(TreeNode *root, int &maxSum) {
        if (not root) return 0;
        int left = max(0, dfs(root->left, maxSum));
        int right = max(0, dfs(root->right, maxSum));
        maxSum = max(maxSum, left + right + root->val);
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};