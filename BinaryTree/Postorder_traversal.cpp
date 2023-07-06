// postorder
class Solution {
    void postorder(TreeNode *root, vector<int> &ans) {
        if (root == nullptr) return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

// Iterative postorder

// better solution using Two stacks
class Solution {
    void postorder(TreeNode *root, vector<int> &ans) {
        if (root == nullptr) return;
        stack<TreeNode *> st1, st2;
        st1.push(root);
        while (!st1.empty()) {
            TreeNode *temp = st1.top();
            st1.pop();
            st2.push(temp);
            if (temp->left) {
                st1.push(temp->left);
            }
            if (temp->right) {
                st1.push(temp->right);
            }
        }
        while (!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }
    }

public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

// optimized solution using one stacks
class Solution {
    void postorder(TreeNode *root, vector<int> &ans) {
        if (root == nullptr) return;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (!st.empty() or cur) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode *temp = st.top();
                if (temp->right) {
                    cur = temp->right;
                } else {
                    st.pop();
                    ans.push_back(temp->val);
                    // all right side node which will be print next.
                    while (!st.empty() and temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
            }
        }
    }

public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};

// own made solution which is more easy to understand

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> postorder;
        if (!root) return postorder;
        stack<TreeNode *> st;
        TreeNode *cur = root;

        while (cur or st.size()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                TreeNode *temp = st.top()->right;
                if (temp) {
                    cur = temp;
                } else {
                    TreeNode *popOut = st.top();
                    st.pop();
                    postorder.push_back(popOut->val);
                    while (st.size() and popOut == st.top()->right) {
                        popOut = st.top();
                        st.pop();
                        postorder.push_back(popOut->val);
                    }
                }
            }
        }
        return postorder;
    }
};