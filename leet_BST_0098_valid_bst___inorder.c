

bool isValidBST(struct TreeNode* root)
{
    int         size;
    int         *n;
    int         *i;

    i = malloc(sizeof(int));
    *i = 0;
    inorder_size(root, i);
    // printf("%d \n", *i); // debugging
    size = *i;
    n = malloc((*i) * sizeof(int));
    *i = 0;
    inorder(root, n, i);
    *i = 0;
    while (++*i < size)
        if (n[*i - 1] >= n[*i])
            return false;
    return true;
}

void    inorder(struct TreeNode *node, int *nums, int *index)
{
    if (!node)
        return ;
    inorder(node->left, nums, index);
    nums[*index] = node->val;
    *index += 1;
    inorder(node->right, nums, index);
}

void    inorder_size(struct TreeNode *node, int *size)
{
    if (!node)
        return ;
    inorder_size(node->left, size);
    *size += 1;
    inorder_size(node->right, size);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
