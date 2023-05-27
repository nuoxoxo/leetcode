class Solution {
public:
    int findTilt(TreeNode* root)
    {
        int     res;

        res = 0;
        dfs(root, res);

        return (res);
    }
    
    int dfs(TreeNode* root, int &res)
    {
        int     L, R;
        
        if(!root)   return (0);
        L = dfs(root->left, res);
        R = dfs(root->right, res);
        res += abs(L - R);

        return (L + R + root->val);
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
