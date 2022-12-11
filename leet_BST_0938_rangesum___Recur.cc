class Solution {
public:
	int rangeSumBST(TreeNode* node, int lo, int hi)
	{
	    if (node == nullptr)
		    return (0);
	    if (lo > hi)
		    return (0);
	    if (node->val < lo)
		    return rangeSumBST(node->right, lo, hi);
	    if (node->val > hi)
		    return rangeSumBST(node->left, lo, hi);
	    return ( node->val + rangeSumBST(node->left, lo, hi) + rangeSumBST(node->right, lo, hi) );
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

