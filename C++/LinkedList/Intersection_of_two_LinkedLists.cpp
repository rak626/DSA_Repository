/*========================================
// Intersection of Two Linked Lists
========================================*/

int findIntersection(Node *firstHead, Node *secondHead) {
    if (!firstHead or !secondHead) return -1;

    Node *a = firstHead, *b = secondHead;

    while (a != b) {
        a = a == NULL ? secondHead : a->next;
        b = b == NULL ? firstHead : b->next;
    }
    return a == NULL ? -1 : a->data;
}
/*
Time Complexity: O(2*max(length of list1,length of list2))
Reason: Uses the same concept of difference of lengths of two lists.

Space Complexity: O(1)
Reason: No extra data structure is used*/