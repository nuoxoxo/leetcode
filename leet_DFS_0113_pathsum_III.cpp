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
    vector<vector<int>> pathSum(TreeNode* node, int targetSum)
    {
        vector<vector<int>>     res;
        vector<int>             tmp;
        int                     pathSum;

        pathSum = 0;
        dfs(node, targetSum, pathSum, res, tmp);
        return res;
    }

    void    dfs(TreeNode *node, int targetSum, int pathSum,
                           vector<vector<int>>& res, vector<int> tmp)
    {
        if (! node)
            return ;
        tmp.push_back(node->val);
        pathSum += node->val;
        if (!node->left && !node->right && pathSum == targetSum)
        {
            res.push_back(tmp);
            return ;
        }
        dfs(node->left, targetSum, pathSum, res, tmp);
        dfs(node->right, targetSum, pathSum, res, tmp);
    }
};
