// Binary Search Tree Iterator

class BSTIterator {
    stack<TreeNode *> st;
    void pushAll(TreeNode *node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode *root) { pushAll(root); }

    int next() {
        int ans = -1;
        if (!st.empty()) {
            TreeNode *temp = st.top();
            st.pop();
            ans = temp->val;
            pushAll(temp->right);
        }
        return ans;
    }

    bool hasNext() { return not st.empty(); }
};