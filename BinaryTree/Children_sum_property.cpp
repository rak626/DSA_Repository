// Children Sum Property in Binary Tree

class Solution {
public:
    void changeTree(TreeNode *root) {
        if (not root) return;
        int childSum = 0;
        if (root->left) childSum += root->left->data;
        if (root->right) childSum += root->right->data;

        if (childSum >= root->data)
            root->data = childSum;
        else {
            if (root->left) root->left->data = root->data;
            if (root->right) root->right->data = root->data;
        }

        changeTree(root->left);
        changeTree(root->right);

        int returnChildSum = 0;
        if (root->left) returnChildSum += root->left->data;
        if (root->right) returnChildSum += root->right->data;
        if (root->left or root->right) root->data = returnChildSum;
    }
};