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
    vector<int> rightSideView(TreeNode* node)
    {
        vector<int> res;
        dfs(res, 0, node);
        return res;
    }

    void    dfs(vector<int>& res, int level, TreeNode *node)
    {
        if (!node)
	{
		return;
	}
        if (level == (int) res.size())
	{
		res.push_back(node->val);
	}
	else
	{
		res[level] = node->val;
	}
        ++level;
        dfs(res, level, node->left);
        dfs(res, level, node->right);
    }
};
