class Solution {
public:
    bool isBalanced(TreeNode* node)
    {
        if (!node)
            return true ;
        return countDepth(node) > 0 ;
    }
    
    int countDepth(TreeNode* node)
    {
        if (!node)
            return 0 ;
        int L = countDepth(node->left) ;
        if (L == -1)
            return L ;
        int R = countDepth(node->right) ;
        if (R == -1)
            return R ;
        if (abs(L - R) > 1)
            return -1;
        return max(L, R) + 1 ;
    }
};
