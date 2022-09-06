/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* pruneTree(struct TreeNode* node)
{
    if (!node)
        return node;
    node->left = pruneTree(node->left);
    node->right = pruneTree(node->right);
    if (!node->left && !node->right && node->val == 0)
        return NULL;
    return node;
}
