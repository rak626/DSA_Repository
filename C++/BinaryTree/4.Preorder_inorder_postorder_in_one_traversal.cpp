// Preorder Inorder Postorder Traversals in One Traversal

#include <bits/stdc++.h>
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root) {
    vector<vector<int>> ans(3);
    if (!root) return ans;
    stack<pair<BinaryTreeNode<int> *, int>> st;
    st.push({root, 1});
    while (!st.empty()) {
        auto it = st.top();
        st.pop();
        // preorder
        if (it.second == 1) {
            ans[1].push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left) {
                st.push({it.first->left, 1});
            }
        }
        // inorder
        else if (it.second == 2) {
            ans[0].push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right) {
                st.push({it.first->right, 1});
            }
        }
        // post order
        else if (it.second == 3) {
            ans[2].push_back(it.first->data);
        }
    }
    return ans;
}