// morris traversal preorder
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorder;
        if (not root) return preorder;
        TreeNode *cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                preorder.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode *prev = cur->left;
                while (prev->right and prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = cur;
                    preorder.push_back(cur->val);
                    cur = cur->left;
                } else {
                    prev->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        return preorder;
    }
};