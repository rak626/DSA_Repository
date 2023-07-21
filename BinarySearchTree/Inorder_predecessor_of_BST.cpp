// inorder predecessor of BST

Node *findPredecessor(Node *root, Node *p) {
    if (not root) return nullptr;
    Node *predecessor = nullptr;
    while (root) {
        if (root->data < p->data) {
            predecessor = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return predecessor;
}