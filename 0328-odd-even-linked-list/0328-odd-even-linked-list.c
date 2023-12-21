/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == NULL || head->next->next == NULL) {
        return head;
    }

    struct ListNode* headOdd = head->next;
    struct ListNode* currEven = head;
    struct ListNode* currOdd = headOdd;
    struct ListNode* curr = headOdd->next;
    int count = 0;
    while (curr != NULL) {
        if (count % 2 == 0) {
            currEven->next = curr; 
            currEven = curr;
        } else {
            currOdd->next = curr;
            currOdd = curr;
        }
        count ++;
        curr = curr->next;
    }
    currEven->next = headOdd;
    currOdd->next = NULL;
    return head;
}