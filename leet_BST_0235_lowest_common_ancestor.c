/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
        int         self = root->val;
        int         pv = p->val;
        int         qv = q->val;

        // dive left if greater than both p and q
        // dive right if less than both p and q

        if (self > pv && self > qv) 
            return lowestCommonAncestor(root->left, p, q);
        if (self < pv && self < qv)
            return lowestCommonAncestor(root->right, p, q);
        return root;
}
