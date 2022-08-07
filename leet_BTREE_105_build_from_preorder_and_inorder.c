/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* po, int posize, int* io, int iosize)
{
    struct TreeNode *node;
    int             head;
    int             i;

    if (!posize || !iosize)
        return NULL;
    if (!(node = malloc(sizeof(struct TreeNode))))
        return NULL;
    head = po[0];
    node->val = head;
    i = -1;
    while (++i < posize)
        if (io[i] == head)
            break ;
    node->left = buildTree(po + 1, i, io, i);
    node->right = buildTree(po + i + 1, posize - i - 1, io + i + 1, io - i - 1);
    return node ;
}
