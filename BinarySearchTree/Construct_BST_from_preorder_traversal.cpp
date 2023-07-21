// Construct Binary Search Tree from Preorder Traversal

// method 1 : Normal bootforce approach to check each node from root if its
// placeable or not. tc : O(n * n); method 2 : sort preorder and we find
// inorder.
//             if we know preorder and inorder we can build tree using binary
//             tree concept; tc: O(nlogn) + O(n); sc: O(n);
// method 3 :

class Solution {
    TreeNode *buildBST(vector<int> &preorder, int &idx, int upperBound) {
        if (idx == preorder.size() or preorder[idx] > upperBound)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = buildBST(preorder, idx, root->val);
        root->right = buildBST(preorder, idx, upperBound);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        int idx = 0;
        return buildBST(preorder, idx, INT_MAX);
    }
};