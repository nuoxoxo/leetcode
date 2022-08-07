class Solution {
public:
    bool hasPathSum(TreeNode* node, int ts)
    {
        if (!node)
            return false ;
        if (!node->left && !node->right)
        {
            if (ts - node->val)
                return false ;
            return true ;
        }
        return (hasPathSum(node->left, ts - node->val) ||
               hasPathSum(node->right, ts - node->val));
    }
};
