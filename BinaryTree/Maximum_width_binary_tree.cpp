// Maximum Width of Binary Tree

class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (not root) return 0;
        queue<pair<TreeNode *, long long>> queueNode;
        queueNode.push({root, 0});
        long long ans = 0;

        while (!queueNode.empty()) {
            long long queueSize = (long long)queueNode.size();
            long long minLevelIndex = queueNode.front().second;
            long long first, last;

            for (int i = 0; i < queueSize; i++) {
                TreeNode *temp = queueNode.front().first;
                // cur_idx = previous idx in  - min idx of that level
                long long cur_idx = queueNode.front().second - minLevelIndex;
                queueNode.pop();
                // storing first or last for ans calculation
                if (i == 0) first = cur_idx;
                if (i == queueSize - 1) last = cur_idx;

                if (temp->left) {
                    queueNode.push({temp->left, cur_idx * 2 + 1});
                }
                if (temp->right) {
                    queueNode.push({temp->right, cur_idx * 2 + 2});
                }
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};