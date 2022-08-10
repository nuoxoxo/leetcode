/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *new_tree(int *, int, int);
struct TreeNode *new_node(int);

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return new_tree(nums, 0, numsSize - 1);
}

struct TreeNode *new_tree(int* nums, int L, int R)
{
    struct TreeNode     *node;
    int                 mid;

    if (L > R)
        return (NULL);
    mid = (R - L) / 2 + L;
    node = new_node(nums[mid]);
    node->left = new_tree(nums, L, mid - 1);
    node->right = new_tree(nums, mid + 1, R);
    return (node);
}

struct TreeNode *new_node(int val)
{
    struct TreeNode     *node = malloc(sizeof(struct TreeNode));

    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
