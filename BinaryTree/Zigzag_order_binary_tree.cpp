// Binary Tree Zigzag Level Order Traversal

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> zigzag;
        if (!root) return zigzag;

        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = 1;

        while (!q.empty()) {
            int queueSize = q.size();
            vector<int> row(queueSize);
            for (int i = 0; i < queueSize; i++) {
                TreeNode *temp = q.front();
                q.pop();

                int index = leftToRight ? i : queueSize - 1 - i;
                row[index] = temp->val;

                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            zigzag.push_back(row);
            leftToRight = !leftToRight;
        }
        return zigzag;
    }
};