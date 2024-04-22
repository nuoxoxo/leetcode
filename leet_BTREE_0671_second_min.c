/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

long long res0 = 2147483648;
long long res1 = 2147483648;

long long res = 2147483648;

void DFS_1(struct TreeNode *);
void DFS_2(struct TreeNode *, int *);

int findSecondMinimumValue(struct TreeNode* root) {

    // vers. 1
    res0 = 2147483648;
    res1 = 2147483648;
    DFS_1(root);
    // return res1 ^ 2147483648 ? (int) res1 : -1;

    /* ****** ****** ****** */

    // vers. 2
    res = 2147483648;
    DFS_2(root, &(root->val));
    return res ^ 2147483648 ? (int) res : -1;
}

void DFS_2(struct TreeNode * node, int * curr) {

    if (!node)
        return ;
    int n = node->val;
    if ( n != *curr && n < res)
        res = n;
    if (res <= n)
        return ;
    DFS_2(node->left, curr);
    DFS_2(node->right, curr);
}

void DFS_1(struct TreeNode * node) {

    if (!node)
        return ;
    int n = node->val;
    if (n < res0)
    {
        res1 = res0;
        res0 = n;
    }
    else if (n != res0 && (n < res1))
    {
        res1 = n;
    }
    DFS_1(node->left);
    DFS_1(node->right);
}

