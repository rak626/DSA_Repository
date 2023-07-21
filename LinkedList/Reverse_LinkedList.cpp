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

// using recursion
ListNode *reverse(ListNode *head) {
    if (!head or !head->next) return head;

    ListNode *newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}