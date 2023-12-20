/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* curr = head;
    int counter = 0;
    while (curr != NULL) {
        curr = curr->next;
        counter += 1;
    }
    if (counter == 1 || counter == 0) {
        return NULL;
    }

    curr = head;
    struct ListNode* pre = NULL;
    n = counter - n;
    counter = 0;
    while (counter != n) {
        pre = curr;
        curr = curr->next;
        counter += 1;
    }
    if (pre == NULL) {
        return curr->next;
    }
    pre->next = curr->next;



    return head;
}