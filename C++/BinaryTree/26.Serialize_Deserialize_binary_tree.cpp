// Serialize and Deserialize Binary Tree

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res = "";
        if (not root) {
            return res;
        }
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode *cur = nodes.front();
            nodes.pop();
            if (cur) {
                res.append(to_string(cur->val) + ',');
            } else {
                res.append("#,");
            }
            if (cur) {
                nodes.push(cur->left);
                nodes.push(cur->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.size() == 0) return nullptr;

        stringstream s(data);

        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode *cur = nodes.front();
            nodes.pop();
            // for find left node
            getline(s, str, ',');
            if (str == "#") {
                cur->left = nullptr;
            } else {
                TreeNode *leftNode = new TreeNode(stoi(str));
                cur->left = leftNode;
                nodes.push(leftNode);
            }
            // for find right node
            getline(s, str, ',');
            if (str == "#") {
                cur->right = nullptr;
            } else {
                TreeNode *rightNode = new TreeNode(stoi(str));
                cur->right = rightNode;
                nodes.push(rightNode);
            }
        }
        return root;
    }
};