#include <stdlib.h>
#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* curr = head;
    int elementCount = 0;
    while (curr != NULL) {
        elementCount++;
        curr = curr->next;
    }
    if (elementCount == 1) {
        return NULL;
    }
    curr = head;
    struct ListNode* prev = NULL;
    int index = 0;
    printf("%i\n", elementCount);
    while (curr != NULL) {
        if (index == (elementCount-n)) {
            if (curr->next == NULL) {
                prev->next = NULL;
                return head;
            } else if (prev == NULL) {
                head = curr->next;
                return head;
            }
            if (prev == NULL) prev = head;
            else prev->next = curr->next;
            return head;
        }
        index++;
        prev = curr;
        curr = curr->next;
    }
    return head;
}
