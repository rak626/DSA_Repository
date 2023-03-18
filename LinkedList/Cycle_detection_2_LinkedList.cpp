/*================================================================================
// Linked List Cycle II detect and find start of cycle
================================================================================*/

Node *firstNode(Node *head) {
  if (!head or !head->next)
    return nullptr;
  Node *fast = head, *slow = head;
  slow = slow->next;
  fast = fast->next->next;
  while (fast and fast->next) {
    if (fast == slow) {
      break;
    }
    slow = slow->next;
    fast = fast->next->next;
  }
  if (!fast or !fast->next)
    return nullptr;
  fast = head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }
  return fast;
}

/*
Time Complexity: O(N)
Reason: We can take overall iterations club it to O(N)

Space Complexity: O(1)
Reason: No extra data structure is used.
*/