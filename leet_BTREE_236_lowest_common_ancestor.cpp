/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define lca lowestCommonAncestor

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        TreeNode        *L, *R;

        if (!node || node == p || node == q) 
            return node;
        L = lca(node->left, p, q);
        R = lca(node->right, p, q);
        if (! L)
            return R;
        if (!R)
            return L;
        return node;
    }
};
