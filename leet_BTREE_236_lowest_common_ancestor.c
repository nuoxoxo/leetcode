/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* node, struct TreeNode* p, struct TreeNode* q) {
    struct  TreeNode    *left;
    struct  TreeNode    *right;

    if (!node || node == p || node == q)
        return node;
    left = lowestCommonAncestor(node->left, p, q);
    right = lowestCommonAncestor(node->right, p, q);
    if (left && right)
        return node;
    if (left)
        return left;
    return right;
}
