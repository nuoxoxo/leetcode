/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int DFS(struct TreeNode *, int);

int sumNumbers(struct TreeNode* root)
{
    return DFS(root, 0);
}

int DFS(struct TreeNode * node, int curr)
{
    if ( ! node)
    {
        return 0;
    }
    curr = curr * 10 + node->val;
    if ( ! node->left && ! node->right)
    {
        return curr;
    }
    return DFS(node->left, curr) + DFS(node->right, curr);
}
