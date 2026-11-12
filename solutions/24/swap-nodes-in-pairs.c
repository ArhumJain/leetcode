#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL) return head;
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* adjacent = curr->next;
    struct ListNode* next;
    if (adjacent != NULL) {
        next = adjacent->next;
    } else return head;
    while (adjacent != NULL && curr != NULL) {
        if (prev == NULL) head = adjacent;
        else prev->next = adjacent;
        adjacent->next = curr;
        curr->next = next;
        prev = curr;
        curr = next;
        if (curr != NULL) adjacent = curr->next;
        if (adjacent != NULL) next = adjacent->next;
    }
    return head;
    
}
