/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* curr = head;
    struct ListNode* pre = NULL;

    while (curr->next != NULL) {
        if (curr->next->val == curr->val) {
            struct ListNode* curr2 = curr;
            while (curr2 != NULL && curr2->val == curr->val) {
                curr2 = curr2->next;
            }

            if (pre == NULL && curr2 == NULL) {
                return NULL;
            }
            if (pre == NULL) {
                head = curr2;
                curr = head;
            } else {
                pre->next = curr2;
                curr = pre;
            }
        } else {
            pre = curr;
            curr = curr->next;
        }
    }
    return head;
}