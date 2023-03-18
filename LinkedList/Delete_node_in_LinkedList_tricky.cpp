/*============================================
// Delete Node In A Linked List in O(1) sol
============================================*/

void deleteNode(LinkedListNode<int> *node) {
  if (!node)
    return;
  node->data = node->next->data;
  node->next = node->next->next;
}