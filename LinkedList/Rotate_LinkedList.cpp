// Rotate Linked List

Node *rotate(Node *head, int k) {
    if (!head or !head->next) return head;
    int len = 1;
    Node *t = head;
    while (t->next) {
        len++;
        t = t->next;
    }
    k = k % len;
    int end = len - k-1;
    t->next = head;
    Node *s = head;
    while (end--) s = s->next;
    head = s->next;
    s->next = nullptr;
    return head;
}
/*
Time Complexity: O(length of list) + O(length of list – (length of list%k))
Reason: O(length of the list) for calculating the length of the list.
O(length of the list – (length of list%k)) for breaking link.

Space Complexity: O(1)
Reason: No extra data structure is used for computation.