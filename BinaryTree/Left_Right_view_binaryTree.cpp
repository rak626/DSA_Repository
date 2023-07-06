// Binary Tree Right/Left Side View

// recursive Solution dfs
class Solution {
    void findRightSideView(TreeNode *root, int level, vector<int> &rightView) {
        if (not root) return;
        if (level == rightView.size()) {
            rightView.push_back(root->val);
        }
        // alternate left and right if its Left View
        findRightSideView(root->right, level + 1, rightView);
        findRightSideView(root->left, level + 1, rightView);
    }

public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> rightView;
        findRightSideView(root, 0, rightView);
        return rightView;
    }
};

// Iterative Solution bfs
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> rightView;
        if (!root) return rightView;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *temp = q.front();
                q.pop();
                if (i == 0) {
                    rightView.push_back(temp->val);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
                if (temp->left) {
                    q.push(temp->left);
                }
            }
        }
        return rightView;
    }
};