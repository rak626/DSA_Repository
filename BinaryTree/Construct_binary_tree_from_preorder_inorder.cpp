// Construct Binary Tree from Preorder and Inorder Traversal

class Solution {
    TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd,
                        vector<int> &inorder, int inStart, int inEnd,
                        map<int, int> &inMap) {
        if (preStart > preEnd or inStart > inEnd) return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int inRootPos = inMap[root->val];
        int countNumsLeft = inRootPos - inStart;
        root->left = buildTree(preorder, preStart + 1, preStart + countNumsLeft,
                               inorder, inStart, inRootPos - 1, inMap);

        root->right = buildTree(preorder, preStart + countNumsLeft + 1, preEnd,
                                inorder, inRootPos + 1, inEnd, inMap);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        TreeNode *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                                   inorder.size() - 1, inMap);
        return root;
    }
};