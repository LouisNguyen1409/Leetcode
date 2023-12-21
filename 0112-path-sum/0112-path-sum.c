/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode* root, int targetSum, int sum, bool* isTrue) {
    if (root == NULL) {
        return;
    }

    sum += root->val;

    // Check if we are at a leaf node and the sum equals targetSum
    if (root->left == NULL && root->right == NULL && sum == targetSum) {
        *isTrue = true;
        return;
    }

    // Continue traversal if a valid path has not been found yet
    if (!*isTrue) {
        traverse(root->left, targetSum, sum, isTrue);
    }

    if (!*isTrue) {
        traverse(root->right, targetSum, sum, isTrue);
    }
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }
    bool isTrue = false;
    traverse(root, targetSum, NULL, &isTrue);
    return isTrue;
}