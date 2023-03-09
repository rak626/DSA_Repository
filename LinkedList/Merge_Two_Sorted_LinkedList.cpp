/*============================================
// Merge Two Sorted Linked Lists
============================================*/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second) {
  Node<int> *head = new Node<int>(0);
  Node<int> *t = head;
  while (first and second) {
    if (first->data <= second->data) {
      t->next = first;
      t = t->next;
      first = first->next;
    } else {
      t->next = second;
      t = t->next;
      second = second->next;
    }
    t->next = nullptr;
  }
  if (first) {
    t->next = first;
  }
  if (second) {
    t->next = second;
  }
  return head->next;
}