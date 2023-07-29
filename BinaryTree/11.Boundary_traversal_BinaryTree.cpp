// Boundary Traversal of binary tree

class Solution {
    bool isLeaf(Node *root) {
        if (!root->left and !root->right) {
            return true;
        }
        return false;
    }
    void addLeftBoundary(Node *root, vector<int> &res) {
        while (root) {
            if (!isLeaf(root)) {
                res.push_back(root->data);
            }
            if (root->left) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }
    void addLeafNodes(Node *root, vector<int> &res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) addLeafNodes(root->left, res);
        if (root->right) addLeafNodes(root->right, res);
    }
    void addRightBoundary(Node *root, vector<int> &res) {
        stack<int> temp;
        while (root) {
            if (!isLeaf(root)) {
                temp.push(root->data);
            }
            if (root->right) {
                root = root->right;
            } else {
                root = root->left;
            }
        }
        while (temp.size()) {
            res.push_back(temp.top());
            temp.pop();
        }
    }

public:
    vector<int> boundary(Node *root) {
        vector<int> res;
        if (not root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root->left, res);
        addLeafNodes(root, res);
        addRightBoundary(root->right, res);
        return res;
    }
};