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
    if (k == 0) return head;
    t->next = head;
    Node *s = head;
    for (int i = 1; i < len - k; i++) {
        s = s->next;
    }
    head = s->next;
    s->next = NULL;
    return head;
}
/*
Time Complexity: O(length of list) + O(length of list – (length of list%k))
Reason: O(length of the list) for calculating the length of the list.
O(length of the list – (length of list%k)) for breaking link.

Space Complexity: O(1)
Reason: No extra data structure is used for computation.