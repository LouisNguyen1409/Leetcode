/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traversal(struct TreeNode* node, int* final, int* size) {
    if (node == NULL) {
        return;
    }

    traversal(node->left, final, size);
    final[*size] = node->val;
    *size += 1;
    traversal(node->right, final, size);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* final = malloc(sizeof(int) * 101);
    int size = 0;
    traversal(root, final, &size);
    *returnSize = size;
    return final;
}