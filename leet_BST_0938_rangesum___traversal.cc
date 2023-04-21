class Solution {
public:
    int rangeSumBST(TreeNode* root, int lo, int hi)
    { 
        // order traversal
        int res = 0;
        order(res, root, lo, hi);
        return res;
    }

    void order(int & res, TreeNode* node, int lo, int hi)
    {
        if ( !node)
            return ;
        int n = node->val;
        if (n <= hi && n >= lo)
            res += n;
        order(res, node->left, lo, hi);
        order(res, node->right, lo, hi);
    }
};
