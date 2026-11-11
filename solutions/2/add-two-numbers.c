#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* sumhead = malloc(sizeof(struct ListNode));
    sumhead->val = 0;
    sumhead->next = NULL;
    struct ListNode* sum = sumhead;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        sum->val += carry;
        carry = 0;
        if (l1 != NULL) {
            sum->val += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum->val += l2->val;
            l2 = l2->next;
        }
        if (sum->val >= 10) {
            carry = 1;
            sum->val -= 10;
        }
        if (l1 != NULL || l2 != NULL || carry != 0) {
            sum->next = malloc(sizeof(struct ListNode));
            sum = sum->next;
            sum->val = 0;
            sum->next = NULL;
        }
    }
    return sumhead;
}
