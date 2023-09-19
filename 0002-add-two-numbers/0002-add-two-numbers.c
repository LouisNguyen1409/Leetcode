/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* newNode(int value);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int over = 0;
    struct ListNode* curr_1 = l1;
    struct ListNode* curr_2 = l2;
    struct ListNode* head = NULL;
    struct ListNode* curr = NULL;
    while (!(curr_1 == NULL && curr_2 == NULL && over == 0)) {
        struct ListNode* new = NULL;
        if (curr_1 != NULL && curr_2 != NULL) {
            if (curr_1->val + curr_2->val + over < 10) {
                new = newNode(curr_1->val + curr_2->val + over);
                over = 0;
            } else {
                int r = (curr_1->val + curr_2->val + over) % 10;
                over = (curr_1->val + curr_2->val + over - r) / 10;
                new = newNode(r);
            }
            if (head == NULL) {
                head = new;
                curr = head;
            } else {
                curr->next = new;
                curr = new;
            }
            curr_1 = curr_1->next;
            curr_2 = curr_2->next;
        } else if (curr_1 != NULL){
            if (curr_1->val + over < 10) {
                new = newNode(curr_1->val + over);
                over = 0;
            } else {
                int r = (curr_1->val + over) % 10;
                over = (curr_1->val + over - r) / 10;
                new = newNode(r);
            }
            curr->next = new;
            curr = new;
            curr_1 = curr_1->next;
        } else if (curr_2 != NULL) {
            if (curr_2->val + over < 10) {
                new = newNode(curr_2->val + over);
                over = 0;
            } else {
                int r = (curr_2->val + over) % 10;
                over = (curr_2->val + over - r) / 10;
                new = newNode(r);
            }
            curr->next = new;
            curr = new;
            curr_2 = curr_2->next;
        } else {
            new = newNode(over);
            curr->next = new;
            curr = new;
            over = 0;
        }
    }
  return head;
}

struct ListNode* newNode(int value) {
    struct ListNode* new = malloc(sizeof(struct ListNode));
    new->val = value;
    new->next = NULL;
    return new;
}
