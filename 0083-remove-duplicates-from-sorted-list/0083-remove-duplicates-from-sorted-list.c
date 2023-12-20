/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
        struct ListNode* curr = head;
    struct ListNode* pre = NULL;
    struct ListNode* next = NULL;  

    while (curr != NULL) {
        pre = curr;
        next = curr->next;
        if (next != NULL && next->val == curr->val) {
            pre->next = next->next;
            curr = pre;
        } else {
            curr = next;
        }
    }
    return head;
}