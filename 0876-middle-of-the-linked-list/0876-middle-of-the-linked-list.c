/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* curr = head;
    int length = 0;
    while (curr != NULL) {
        length += 1;
        curr = curr->next;
    }
    int middle = ceil(length / 2);
    struct ListNode* ans = NULL;
    curr = head;
    int counter = 0;
    while (curr != NULL) {
        if (counter == middle) {
            ans = curr;
            break;
        }
        curr = curr->next;
        counter += 1;
    }
    return ans;
}