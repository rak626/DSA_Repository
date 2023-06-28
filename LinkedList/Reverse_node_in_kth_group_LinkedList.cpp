/*========================================
// Reverse Nodes in k-Group
========================================*/

class Solution {
public:
    int lengthOfLL(ListNode *head) {
        int cnt = 0;
        while (head) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head or !head->next) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy, *cur = dummy, *nex = dummy;
        int length = lengthOfLL(head);
        while (length >= k) {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            length -= k;
        }
        return dummy->next;
    }
};

/* ============================================================================
 codestudio code using variable size bucket
============================================================================ */

int lengthOfLL(Node *head) {
    int cnt = 0;
    while (head) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]) {
    // if (!head or !head->next) return head;
    Node *dummy = new Node(0);
    dummy->next = head;
    Node *pre = dummy, *cur = dummy, *nex = dummy;
    int length = lengthOfLL(head);
    int idx = 0;
    while (idx < n and length > 0) {
        cur = pre->next;
        nex = cur->next;
        int rep = length >= b[idx] ? b[idx] : length;
        if (rep == 0) {
            idx++;
            continue;
        }
        for (int i = 1; i < rep; i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= rep;
        idx++;
    }
    return dummy->next;
}

/*Time Complexity: O(N)
Reason: Nested iteration with O((N/k)*k) which makes it equal to O(N).

Space Complexity: O(1)
Reason: No extra data structures are used for computation.*/
