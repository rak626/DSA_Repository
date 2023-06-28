/*================================================================================
// Linked List Cycle II detect and find start of cycle
================================================================================*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head or !head->next) return nullptr;
        ListNode *fast = head, *slow = head, *entry = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return nullptr;
    }
};

/*
Time Complexity: O(N)
Reason: We can take overall iterations club it to O(N)

Space Complexity: O(1)
Reason: No extra data structure is used.
*/