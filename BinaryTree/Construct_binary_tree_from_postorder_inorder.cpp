// Construct Binary Tree from Inorder and Postorder Traversal

class Solution {
    TreeNode *buildTree(vector<int> &postorder, int postStart, int postEnd,
                        vector<int> &inorder, int inStart, int inEnd,
                        map<int, int> &inMap) {
        if (postStart > postEnd or inStart > inEnd) return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRootPos = inMap[root->val];
        int countNumsLeft = inRootPos - inStart;
        root->left =
            buildTree(postorder, postStart, postStart + countNumsLeft - 1,
                      inorder, inStart, inRootPos - 1, inMap);

        root->right =
            buildTree(postorder, postStart + countNumsLeft, postEnd - 1,
                      inorder, inRootPos + 1, inEnd, inMap);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        TreeNode *root = buildTree(postorder, 0, postorder.size() - 1, inorder,
                                   0, inorder.size() - 1, inMap);
        return root;
    }
};