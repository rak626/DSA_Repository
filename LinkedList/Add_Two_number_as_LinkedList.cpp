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