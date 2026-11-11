struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next; 
    }
    return prev;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* doubleIt(struct ListNode* head) {
    head = reverse(head);
    int carry = 0;
    struct ListNode* curr = head;
    while (curr != NULL) {
        int total = (curr->val * 2) + carry;
        carry = total/10;
        curr->val = total % 10;
        if (curr->next == NULL && carry != 0) {
            curr->next = malloc(sizeof(struct ListNode));
            curr->next->next = NULL;
            curr->next->val = carry;
            break;
        } else {
            curr = curr->next;
        }
    }
    return reverse(head);
}
