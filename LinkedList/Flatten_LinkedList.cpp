/*========================================
Flatten A Linked List
========================================*/

// merge with while loop
Node *merge(Node *first, Node *second) {
    Node *dummy = new Node(0);
    Node *temp = dummy;
    while (first and second) {
        if (first->data <= second->data) {
            temp->child = first;
            first = first->child;
        } else {
            temp->child = second;
            second = second->child;
        }
        temp->next = nullptr;
        temp = temp->child;
    }
    if (first) {
        temp->child = first;
    }
    if (second) {
        temp->child = second;
    }
    return dummy->child;
}

// merge with recursion

Node *merge(Node *first, Node *second) {
    if (!first) return second;
    if (!second) return first;
    Node *res = nullptr;
    if (first->data <= second->data) {
        res = first;
        res->child = merge(first->child, second);
    } else {
        res = second;
        res->child = merge(first, second->child);
    }
    res->next = NULL;
    return res;
}

Node *flattenLinkedList(Node *head) {
    if (!head or !head->next) return head;
    head->next = flattenLinkedList(head->next);
    head = merge(head, head->next);
    return head;
}

/*
Time Complexity: O(N), where N is the total number of nodes present
Reason: We are visiting all the nodes present in the given list.

Space Complexity: O(1)
Reason: We are not creating new nodes or using any other data structure.