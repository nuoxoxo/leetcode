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
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* L, TreeNode* R)
    {
        if (node->val > L->val && node->val > R->val)
            return lowestCommonAncestor(node->left, L, R);
        if (node->val < L->val && node->val < R->val)
            return lowestCommonAncestor(node->right, L, R);
        return node ;
    }
};

