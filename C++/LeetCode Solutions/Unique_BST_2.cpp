class Solution {
public:
    map<pair<int, int>, vector<TreeNode*> > dp;
    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            return {nullptr};
        }
        if (start == end) {
            return {new TreeNode(start)};
        }
        // memoize;
        if (dp.count({start, end})) return dp[{start, end}];

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = helper(start, i - 1);
            vector<TreeNode*> right = helper(i + 1, end);

            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(i, l, r);
                    res.push_back(root);
                }
            }
        }
        return dp[{start, end}] = res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};