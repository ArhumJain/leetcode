typedef struct stringNode {
    char* originalString;
    char* sortedString;
} stringNode;

int sortString(const void* A, const void* B) {
    char* a = (char*) A;
    char* b = (char*) B;
    if (*a < *b) return -1;
    else if (*a > *b) return 1;
    return 0;
}

int sortNodes(const void* A, const void* B) {
    stringNode* a = *(stringNode**) A;
    stringNode* b = *(stringNode**) B;
    char* c1 = a->sortedString;
    char* c2 = b->sortedString;
    return strcmp(c1, c2);   
}

stringNode* createStringNode(char* s) {
    stringNode* node = malloc(sizeof(stringNode));
    node->originalString = s;
    int stringSize = 0; // includes null termination
    while (*s != '\0') {
        stringSize++;
        s++;
    }
    stringSize++;
    node->sortedString = malloc(stringSize * sizeof(char));
    memcpy(node->sortedString, node->originalString, sizeof(char) * stringSize);
    qsort(node->sortedString, stringSize-1, sizeof(char), sortString);
    return node;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    stringNode** nodes = malloc(strsSize * sizeof(stringNode*));
    for (int i = 0; i < strsSize; i++) {
        nodes[i] = createStringNode(strs[i]);
    }
    qsort(nodes, strsSize, sizeof(stringNode*), sortNodes);
    int index = 0;
    int groupedIndex = 0;
    char*** grouped = malloc(strsSize * sizeof(char**));
    int* columnSizes = malloc(strsSize * sizeof(int));
    stringNode* curr = nodes[0];
    int currAnagramIndex = 0;
    while (index < strsSize) {
        if (strcmp(nodes[index]->sortedString, curr->sortedString) == 0) {
            currAnagramIndex++;
        } 
        if (strcmp(nodes[index]->sortedString, curr->sortedString) != 0) {
            grouped[groupedIndex] = malloc((currAnagramIndex) * sizeof(char*));
            for (int i = 0; i < currAnagramIndex; i++) {
                grouped[groupedIndex][i] = nodes[i + index - currAnagramIndex]->originalString;
            }
            columnSizes[groupedIndex] = currAnagramIndex;
            groupedIndex++;
            curr = nodes[index];
            currAnagramIndex = 1;
        }
        index++;
    }
    grouped[groupedIndex] = malloc((currAnagramIndex) * sizeof(char*));
    for (int i = 0; i < currAnagramIndex; i++) {
        grouped[groupedIndex][i] = nodes[i + index - currAnagramIndex]->originalString;
    }
    columnSizes[groupedIndex] = currAnagramIndex;
    groupedIndex++;
    *returnSize = groupedIndex;
    *returnColumnSizes = columnSizes;
    for (int i = 0; i < strsSize; i++) {
        free(nodes[i]->sortedString);
        free(nodes[i]);
    }
    free(nodes);
    return grouped;
}
