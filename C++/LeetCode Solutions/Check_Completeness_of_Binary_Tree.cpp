class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool gotNull = false;
        while (q.size()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == nullptr) {
                gotNull = true;
            } else {
                if (gotNull) return false;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return true;
    }
};