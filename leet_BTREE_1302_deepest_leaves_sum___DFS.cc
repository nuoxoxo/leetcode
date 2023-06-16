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
    int deepestLeavesSum(TreeNode* node)
    {
        int depth = 0;
        int level = 0;
        int res = 0;
        DFS(node, res, depth, level);
        return res;
    }

    void    DFS(TreeNode* node, int &res, int &depth, int level)
    {
        if (!node)
            return ;
        if (level == depth)
        {
            res += node->val;
        }
        else if (level > depth)
        {
            res = node->val;
            depth = level;
        }
        DFS(node->left, res, depth, level + 1);
        DFS(node->right, res, depth, level + 1);
    }
};
