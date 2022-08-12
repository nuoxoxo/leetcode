/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
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
};
