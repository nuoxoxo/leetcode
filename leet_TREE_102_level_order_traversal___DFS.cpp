
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;

        if (!root)
            return {};
        dfs(res, root, 0);
        return res;
    }

    void    dfs(vector<vector<int>>& res, TreeNode *node, int level)
    {
        if (!node)
            return ;
        if (res.size() == level)
            res.push_back(vector<int>());
        res[level].push_back(node->val);
        dfs(res, node->left, level + 1);
        dfs(res, node->right, level + 1);
    }
};

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

