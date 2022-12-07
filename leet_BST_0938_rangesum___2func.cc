class Solution {
public:
	int	rangeSumBST(TreeNode* root, int low, int high)
	{
		int	res = 0;

		recur(res, root, low, high);
		return (res);
	}

	void	recur(int & res, TreeNode* node, int lo, int hi)
	{
		if (node == nullptr)
			return ;
		if (node->val <= hi && node->val >= lo)
			res += node->val;
		recur(res, node->right, lo, hi);
		recur(res, node->left, lo, hi);
	}
};
