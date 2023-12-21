/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countGoodNodes(struct TreeNode* node, int maxVal) {
    if (node == NULL) {
        return 0;
    }
    
    int count = 0;
    if (node->val >= maxVal) {
        count = 1;
        maxVal = node->val;
    }
    
    count += countGoodNodes(node->left, maxVal);
    count += countGoodNodes(node->right, maxVal);
    
    return count;
}

int goodNodes(struct TreeNode* root) {
    return countGoodNodes(root, root->val);
}