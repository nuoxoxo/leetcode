class Solution {
public:
	int maxAncestorDiff(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}
		return solve(root, root->val, root->val);
	}

	int solve(TreeNode *root, int most, int least)
	{
		int	L, R;

		if (!root)
		{
			return (most - least);
		}
		most = max(most, root->val);
		least = min(least, root->val);
		L = solve(root->left, most, least);
		R = solve(root->right, most, least);

		return max(L, R);
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
