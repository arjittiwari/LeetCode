/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* next = head;
    struct ListNode* next2next = head;
    if (!head) {
        return(NULL);
    }
    while(next2next && next2next->next) {
        next = next->next;
        next2next = next2next->next->next;
    }
    return(next);
}