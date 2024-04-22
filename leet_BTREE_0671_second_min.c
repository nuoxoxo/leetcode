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

void recurse(struct TreeNode *);

int findSecondMinimumValue(struct TreeNode* root) {

    res0 = 2147483648;
    res1 = 2147483648;
    recurse(root);
    return res1 ^ 2147483648 ? (int) res1 : -1;
}

void recurse(struct TreeNode * node) {

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
    recurse(node->left);
    recurse(node->right);
}

