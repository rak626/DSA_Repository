// All Nodes Distance K in Binary Tree

class Solution {
    void markUpParent(TreeNode *root,
                      unordered_map<TreeNode *, TreeNode *> &parent_track) {
        if (not root) return;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode *node = nodes.front();
            nodes.pop();
            if (node->left) {
                parent_track[node->left] = node;
                nodes.push(node->left);
            }
            if (node->right) {
                parent_track[node->right] = node;
                nodes.push(node->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        unordered_map<TreeNode *, TreeNode *> parent_track;
        markUpParent(root, parent_track);

        int dis = 0;
        queue<TreeNode *> nodes;
        unordered_map<TreeNode *, bool> vis;
        nodes.push(target);
        vis[target] = true;
        while (!nodes.empty()) {
            int size = nodes.size();
            if (dis++ == k) break;
            for (int i = 0; i < size; i++) {
                TreeNode *cur = nodes.front();
                nodes.pop();
                if (cur->left and !vis[cur->left]) {
                    nodes.push(cur->left);
                    vis[cur->left] = true;
                }
                if (cur->right and !vis[cur->right]) {
                    nodes.push(cur->right);
                    vis[cur->right] = true;
                }
                if (parent_track[cur] and !vis[parent_track[cur]]) {
                    nodes.push(parent_track[cur]);
                    vis[parent_track[cur]] = true;
                }
            }
        }
        vector<int> result;
        while (not nodes.empty()) {
            result.push_back(nodes.front()->val);
            nodes.pop();
        }
        return result;
    }
};