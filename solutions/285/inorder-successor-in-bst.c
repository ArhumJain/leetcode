#include <stdlib.h>
#include <stdbool.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* recurse(struct TreeNode* curr, struct TreeNode* p) {
    if (curr == NULL) return NULL;
    if (curr == p) {
        if (curr->right != NULL) {
            struct TreeNode* successor = curr->right;
            struct TreeNode* left = curr->right->left;
            while (left != NULL) {
                successor = left;
                left = left->left;
            }
            return successor;
        }
        else return p; 
    }
    struct TreeNode* left = recurse(curr->left, p);
    struct TreeNode* right = recurse(curr->right, p);
    if (left == p) return curr;
    else if (left != NULL) return left;
    if (right == p) return p;
    else if (right != NULL) return right;
    return NULL;
}
struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p) {
    struct TreeNode* ret = recurse(root, p);
    if (ret != p && ret != NULL) return ret;
    return NULL;
}
