// Vertical Order Traversal of a Binary Tree
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (not root) return res;
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (q.size()) {
            TreeNode* node = q.front().first;
            int level = q.front().second.first;
            int width = q.front().second.second;
            q.pop();
            mp[width][level].insert(node->val);
            if (node->left) q.push({node->left, {level + 1, width - 1}});
            if (node->right) q.push({node->right, {level + 1, width + 1}});
        }
        for (auto it1 : mp) {
            vector<int> ans;
            for (auto it2 : it1.second) {
                for (auto it3 : it2.second) {
                    ans.push_back(it3);
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};