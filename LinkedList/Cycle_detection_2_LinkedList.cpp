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
// -------------------------------------------Ai generated ------------------------------------------------

ListNode *detectCycle(ListNode *head) {
    // Check if the head node or the next node is null, indicating an empty or single-node list.
    if (!head or !head->next)
        return nullptr;
    
    // Initialize two pointers, 'fast' and 'slow', both pointing to the head node.
    ListNode *fast = head, *slow = head;
    
    // Move the 'slow' pointer one step ahead.
    slow = slow->next;
    
    // Move the 'fast' pointer two steps ahead.
    fast = fast->next->next;
    
    // Iterate until the 'fast' pointer reaches the end of the list or encounters a cycle.
    while (fast and fast->next) {
        // If the 'fast' and 'slow' pointers meet, it indicates the presence of a cycle.
        if (fast == slow) {
            break;
        }
        
        // Move the 'slow' pointer one step ahead.
        slow = slow->next;
        
        // Move the 'fast' pointer two steps ahead.
        fast = fast->next->next;
    }
    
    // If the 'fast' pointer or its next node is null, there is no cycle in the list.
    if (!fast or !fast->next)
        return nullptr;
    
    // Reset the 'fast' pointer to the head of the list.
    fast = head;
    
    // Iterate until the 'fast' and 'slow' pointers meet again, which identifies the cycle's starting point.
    while (fast != slow) {
        // Move both pointers one step ahead in each iteration.
        fast = fast->next;
        slow = slow->next;
    }
    
    // Return the node where the cycle begins.
    return fast;
}
