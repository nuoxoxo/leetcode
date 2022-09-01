/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root)
    {
        return dfs(root, root->val);
    }

    int dfs(TreeNode *node, int cur)
    {
        int res = 0;

        if (node->val >= cur)
        {
            res++;
            cur = node->val;
        }
        if (node->left)
            res += dfs(node->left, cur);
        if (node->right)
            res += dfs(node->right, cur);
        return res;
    }
};
