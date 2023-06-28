// Ceil from BST

int findCeil(BinaryTreeNode<int> *node, int x) {
    int ceil = -1;
    while (node) {
        if (node->data == x) {
            return x;
        }
        if (node->data < x) {
            node = node->right;
        } else {
            ceil = node->data;
            node = node->left;
        }
    }
    return ceil;
}