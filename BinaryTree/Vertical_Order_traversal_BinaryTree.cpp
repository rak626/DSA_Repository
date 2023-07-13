// Vertical Order Traversal of a Binary Tree

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        
        while (!todo.empty()) {
            TreeNode *temp = todo.front().first;
            int vt = todo.front().second.first;
            int hr = todo.front().second.second;
            todo.pop();
            nodes[vt][hr].insert(temp->val);
            if (temp->left) {
                todo.push({temp->left, {vt - 1, hr + 1}});
            }
            if (temp->right) {
                todo.push({temp->right, {vt + 1, hr + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};