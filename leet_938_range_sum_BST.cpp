class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        int N = 0;

        helper(N, root, low, high);

        return (N);
    }
    
    void    helper(int& N, TreeNode* p, int low, int high)
    {
        if (!p)     return ;
        if (p->val <= high && p->val >= low)    N += p->val;
        helper(N, p->right, low, high);
        helper(N, p->left, low, high);
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), \
 *     right(right) {}
 * };
 */
