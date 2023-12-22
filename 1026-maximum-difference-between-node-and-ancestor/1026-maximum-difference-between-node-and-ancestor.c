/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int traverse(struct TreeNode* node, int max, int min) {
    if (node == NULL) {
        return max - min;
    }

    if (min > node->val) {
        min = node->val;
    }
    if (max < node->val) {
        max = node->val;
    }


    int left = traverse(node->left, max, min);
    int right = traverse(node->right, max, min);

    if (left > right) {
        return left;
    }

    return right;
}

int maxAncestorDiff(struct TreeNode* root) {
    if (root == NULL) return 0;
    return traverse(root, root->val, root->val);;
}