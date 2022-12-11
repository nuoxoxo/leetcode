class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        int     res;

        res = (int) -1e9;
        fn(root, res);
        return res;
    }

    int fn(TreeNode *node, int & record)
    {
        int     val, l, r;

        if (!node)
            return 0;
        val = node->val;
        l = fn(node->left, record);
        r = fn(node->right, record);
        val = max(
            {val, val + l, val + r, val + l + r}
        );
        record = max(val, record);
        val = node->val;
        return max(
            {val, val + l, val + r}
        );

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
