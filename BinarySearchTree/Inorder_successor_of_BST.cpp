// inorder Successor of BST

class Solution {
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node *inOrderSuccessor(Node *root, Node *x) {
        if (not root) return nullptr;
        Node *successor = nullptr;
        while (root) {
            if (root->val > x->val) {
                successor = root;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return successor;
    }
};