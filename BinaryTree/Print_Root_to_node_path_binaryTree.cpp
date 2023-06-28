// Print Root to Node Path in Binary Tree

bool findPath(TreeNode *root, vector<int> &path, int target) {
    if (not root) return false;
    path.push_back(root->val);
    if (root->val == target) return true;

    if (findPath(root->left, path, target) or
        findPath(root->right, path, target)) {
        return true;
    }
    path.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode *root, int target) {
    vector<int> path;
    if (root == nullptr) return path;
    findPath(root, path, target);
    return path;
}