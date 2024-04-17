/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void DFS(struct TreeNode *, int, int, int*);

int rangeSumBST(struct TreeNode* root, int low, int high)
{
    int res = 0;
    // DFS(root, low, high, & res);
    Inorder(root, low, high, & res);
    return res;
}

void Inorder(struct TreeNode* node, int low, int high, int * res)
{
    if ( ! node)
        return ;
    Inorder(node->left, low, high, res);
    int n = node->val;
    if (low <= n && n <= high)
        * res += n;
    Inorder(node->right, low, high, res);
}

void DFS(struct TreeNode* node, int low, int high, int * res)
{
    if ( ! node)
        return ;
    int n = node->val;
    if (low <= n && n <= high)
    {
        * res += n;
    }
    if (low < n)
    {
        DFS(node->left, low, high, res);
    }
    if (n < high)
    {
        DFS(node->right, low, high, res);
    }
}

