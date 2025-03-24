/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* temp = head;
    struct ListNode* temp_next;
    if (!head) {
        return(NULL);
    }
    temp_next = head->next;
    temp->next = NULL;
    while (temp_next) {
        head = temp_next;
        temp_next = temp_next->next;
        head->next = temp;
        temp = head;
    }
    return (head);
}