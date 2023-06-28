/* ==========================================================
Clone a Linked List with random and next pointer
========================================================== */

// brute force using hashmap

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return head;
        Node *itr = head;
        unordered_map<Node *, Node *> dc;
        while (itr) {
            Node *t = new Node(itr->val);
            dc[itr] = t;
            itr = itr->next;
        }
        itr = head;
        while (itr) {
            Node *cur = dc[itr];
            cur->next = dc[itr->next];
            cur->random = dc[itr->random];

            itr = itr->next;
        }
        return dc[head];
    }
};

// optimised solution , No extra space

/*1. create deep copy beside each node
2. connect random pointer
3. separate deep copy from original one*/

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return head;
        Node *itr = head;
        while (itr) {
            Node *t = new Node(itr->val);
            t->next = itr->next;
            itr->next = t;
            itr = t->next;
        }
        itr = head;
        while (itr) {
            if (itr->random) {
                itr->next->random = itr->random->next;
            }
            itr = itr->next->next;
        }
        itr = head;
        Node *front = NULL;
        Node *dummy = new Node(-1);
        Node *pre = dummy;
        while (itr) {
            front = itr->next->next;
            pre->next = itr->next;
            itr->next = front;
            pre = pre->next;
            itr = itr->next;
        }
        return dummy->next;
    }
};

// code studio

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head) {
    if (!head) return head;
    LinkedListNode<int> *itr = head;
    while (itr) {
        LinkedListNode<int> *t = new LinkedListNode<int>(itr->data);
        t->next = itr->next;
        itr->next = t;
        itr = t->next;
    }
    itr = head;
    while (itr) {
        itr->next->random = itr->random ? itr->random->next : NULL;
        itr = itr->next->next;
    }
    itr = head;
    LinkedListNode<int> *front = NULL;
    LinkedListNode<int> *dummy = new LinkedListNode<int>(-1);
    LinkedListNode<int> *pre = dummy;
    while (itr) {
        front = itr->next->next;
        pre->next = itr->next;
        itr->next = front;
        pre = pre->next;
        itr = itr->next;
    }
    return dummy->next;
}