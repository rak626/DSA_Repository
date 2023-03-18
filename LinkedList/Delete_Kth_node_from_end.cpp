/*============================================
// Delete Kth node From End
============================================*/

LinkedListNode<int> *removeKthNode(LinkedListNode<int> *head, int K) {
  if (!head or K == 0)
    return head;
  LinkedListNode<int> *d = new LinkedListNode<int>(0);
  d->next = head;
  LinkedListNode<int> *fast = d, *slow = d;
  while (K--) {
    fast = fast->next;
  }
  while (fast->next) {
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = slow->next->next;
  return d->next;
}