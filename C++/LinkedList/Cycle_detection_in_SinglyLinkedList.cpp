/*============================================================
// Cycle Detection in a Singly Linked List
==============================================================*/

bool detectCycle(Node *head) {
    if (!head) return 0;
    Node *d = new Node(0);
    d->next = head;
    Node *fast = head->next, *slow = d;
    while (fast and fast->next) {
        if (fast == slow) {
            return 1;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return 0;
}

/*Time Complexity: O(N)
Reason: In the worst case, all the nodes of the list are visited.

Space Complexity: O(1)
Reason: No extra data structure is used.*/