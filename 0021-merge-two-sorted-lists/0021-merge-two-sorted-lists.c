/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* ans = NULL;
    struct ListNode* curr = NULL;
    while (list1 != NULL && list2 != NULL) {
        struct ListNode* new = malloc(sizeof(struct ListNode));
        if (list1->val <= list2->val) {
            new->val = list1->val;
            new->next = NULL;
            if (ans == NULL) {
                ans = new;
            } else {
                curr->next = new;
            }
            curr = new;
            list1 = list1->next;
        } else {
            new->val = list2->val;
            new->next = NULL;
            if (ans == NULL) {
                ans = new;
            } else {
                curr->next = new;
            }
            curr = new;
            list2 = list2->next;   
        }
    }
    while (list1 != NULL) {
        struct ListNode* new = malloc(sizeof(struct ListNode));
        new->val = list1->val;
        new->next = NULL;
        if (ans == NULL) {
            ans = new;
        } else {
            curr->next = new;
        }
        curr = new;
        list1 = list1->next;
    }

    while (list2 != NULL) {
        struct ListNode* new = malloc(sizeof(struct ListNode));
        new->val = list2->val;
        new->next = NULL;
        if (ans == NULL) {
            ans = new;
        } else {
            curr->next = new;
        }
        curr = new;
        list2 = list2->next;
    }

    return ans;
}