/*============================================
// Middle Of Linked List
============================================*/

Node *findMiddle(Node *head) {
  Node *fast = head, *slow = head;
  while (fast and fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}