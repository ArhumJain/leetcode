#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct Node {
    struct Node* prev;
    struct Node* next;
    bool isOperation;
    int val;
    char op;
} Node;
Node* createNode(Node* prev, bool operation, char op, int val) {
    Node* node = malloc(sizeof(struct Node));
    node->prev = prev;
    node->next = NULL;
    node->isOperation = operation;
    if (operation) {
        node->op = op;
        node->val = 0;
    } else {
        node->val = val;
        node->op = '\0';
    }
    if (prev != NULL) prev->next = node;
    return node;
}
int getInt(const char* token) {
    char c = *token;
    int negative = 1;
    if (c == '-') {
        negative = -1;
        token++;
        c = *token;
    }
    int out = 0;
    while (c != '\0') {
        out = out * 10 + (c - '0');
        token++;
        c = *token;
    }
    return out * negative;
}
int evalRPN(char** tokens, int tokensSize) {
    Node* operations[10003];
    int operationCount = 0;
    Node* head = createNode(NULL, false, ' ', 0);
    Node* prev = head;
    for (int i = 0; i < tokensSize; i++) {
        printf("%c ", *(tokens[i]));
        char c = *(tokens[i]);
        if (tokens[i][1] == '\0' && (c == '+' || c == '-' || c == '*' || c == '/')) {
            operations[operationCount] = createNode(prev, true, c, 0);
            operationCount++;
        } else {
            createNode(prev, false, ' ', getInt(tokens[i]));
        }
        prev = prev->next;
    }

    for (int i = 0; i < operationCount; i++) {
        Node* operationNode = operations[i];
        int val;
        switch (operationNode->op) {
            case '+':
                val = operationNode->prev->val + operationNode->prev->prev->val;
                break;
            case '-':
                val = operationNode->prev->prev->val - operationNode->prev->val;
                break;
            case '*':
                val = operationNode->prev->val * operationNode->prev->prev->val;
                break;
            case '/':
                val = operationNode->prev->prev->val / operationNode->prev->val;
                break;
        }
        Node* newNode;
        if (operationNode->prev->prev->prev != NULL) {
            newNode = createNode(operationNode->prev->prev->prev, false, ' ', val);
        } else {
            newNode = createNode(NULL, false, ' ', val);
        }
        if (operationNode->next != NULL) {
            newNode->next = operationNode->next;
            operationNode->next->prev = newNode;
        }
        free(operationNode->prev->prev);
        free(operationNode->prev);
        free(operationNode);
    }
    int val = head->next->val;
    free(head->next);
    free(head);
    return val;
}
