// Two Sum IV - Input is a BST

// method 1 : take inorder of BST which is sorted in acending order
//            use two sum technique of Array

class BSTIterator {
    stack<TreeNode *> st;
    bool reverse;
    void pushAll(TreeNode *node) {
        while (node) {
            st.push(node);
            if (reverse) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode *root, bool isreverse) {
        reverse = isreverse;
        pushAll(root);
    }

    int next() {
        int ans = -1;
        if (!st.empty()) {
            TreeNode *temp = st.top();
            st.pop();
            ans = temp->val;
            if (reverse) {
                pushAll(temp->left);
            } else {
                pushAll(temp->right);
            }
        }
        return ans;
    }

    bool hasNext() { return not st.empty(); }
};

class Solution {
public:
    bool findTarget(TreeNode *root, int k) {
        if (not root) return false;
        BSTIterator l(root, 0);
        BSTIterator r(root, 1);

        int i = l.next();
        int j = r.next();  // actually r.before()
        while (i <= j) {
            if (i + j == k) return true;
            if (i + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;
    }
};