/*============================================
// Reverse Linked List
============================================*/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
  LinkedListNode<int> *prev = nullptr, *cur = head, *next = nullptr;
  while (cur) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}