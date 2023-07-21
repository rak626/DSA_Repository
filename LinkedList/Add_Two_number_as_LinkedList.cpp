/*============================================
// Add Two Numbers As Linked Lists
============================================*/

Node *addTwoNumbers(Node *head1, Node *head2) {
    int c = 0, sum = 0;
    Node *d = new Node(-1);
    Node *t = d;
    while (head1 and head2) {
        sum = head1->data + head2->data + c;
        c = sum > 9 ? 1 : 0;
        head1->data = sum % 10;
        t->next = head1;
        t = t->next;
        head1 = head1->next;
        head2 = head2->next;
    }
    while (head1) {
        sum = head1->data + c;
        c = sum > 9 ? 1 : 0;
        head1->data = sum % 10;
        t->next = head1;
        t = t->next;
        head1 = head1->next;
    }
    while (head2) {
        sum = head2->data + c;
        c = sum > 9 ? 1 : 0;
        head2->data = sum % 10;
        t->next = head2;
        t = t->next;
        head2 = head2->next;
    }
    if (c) {
        t->next = new Node(c);
    }
    return d->next;
}

// -------------------------------AI generated ----------------------

Node *addTwoNumbers(Node *head1, Node *head2) {
    int c = 0, sum = 0;              // Variables to store carry and sum
    Node *d = new Node(-1);          // Create a dummy node for the result
    Node *t = d;                     // Pointer to traverse the result list
    
    // Traverse both linked lists until one of them reaches the end
    while (head1 and head2) {
        sum = head1->data + head2->data + c;    // Add current digits and carry
        c = sum > 9 ? 1 : 0;                     // Calculate the new carry
        head1->data = sum % 10;                  // Update the current digit
        
        t->next = head1;          // Connect the current node to the result list
        t = t->next;              // Move the result list pointer forward
        head1 = head1->next;      // Move the input list pointers forward
        head2 = head2->next;
    }
    
    // Handle remaining digits in the first linked list
    while (head1) {
        sum = head1->data + c;     // Add current digit and carry
        c = sum > 9 ? 1 : 0;       // Calculate the new carry
        head1->data = sum % 10;    // Update the current digit
        
        t->next = head1;          // Connect the current node to the result list
        t = t->next;              // Move the result list pointer forward
        head1 = head1->next;      // Move the input list pointer forward
    }
    
    // Handle remaining digits in the second linked list
    while (head2) {
        sum = head2->data + c;     // Add current digit and carry
        c = sum > 9 ? 1 : 0;       // Calculate the new carry
        head2->data = sum % 10;    // Update the current digit
        
        t->next = head2;          // Connect the current node to the result list
        t = t->next;              // Move the result list pointer forward
        head2 = head2->next;      // Move the input list pointer forward
    }
    
    if (c) {
        t->next = new Node(c);    // If there is a remaining carry, add a new node
    }
    
    return d->next;               // Return the head of the result list (excluding the dummy node)
}
