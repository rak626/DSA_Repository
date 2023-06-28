/*========================================
// Palindrome Linked List
========================================*/

LinkedListNode<int> *reverseLL(LinkedListNode<int> *head) {
    if (!head or !head->next) return head;
    LinkedListNode<int> *prev = nullptr, *cur = head, *nex = nullptr;
    while (cur) {
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if (!head or !head->next) return 1;
    LinkedListNode<int> *dummy = new LinkedListNode<int>(0);
    dummy->next = head;
    LinkedListNode<int> *fast = dummy, *slow = dummy, *start = head,
                        *mid = dummy;
    while (fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseLL(slow->next);
    mid = slow->next;
    while (mid) {
        if (start->data != mid->data) {
            return 0;
        }
        start = start->next;
        mid = mid->next;
    }
    // slow->next = reverseLL(slow->next);
    return 1;
}

/*Time Complexity: O(N/2)+O(N/2)+O(N/2)
Reason: O(N/2) for finding the middle element, reversing the list from the
middle element, and traversing again to find palindrome respectively.

Space Complexity: O(1)
Reason: No extra data structures are used.
*/