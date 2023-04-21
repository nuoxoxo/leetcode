class Solution {
public:
    int rangeSumBST(TreeNode* root, int lo, int hi)
    { 
        // DFS
        if (root == NULL)
            return 0;
        if ( !(root->val < lo || root->val > hi))
            return root->val + rangeSumBST(root->left, lo, hi) + rangeSumBST(root->right, lo, hi);
        return rangeSumBST(root->left, lo, hi) + rangeSumBST(root->right, lo, hi);
    }
};
