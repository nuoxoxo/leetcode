class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> v1;
        vector<int> v2;
        
        dfs_on_single_tree(root1, v1);
        dfs_on_single_tree(root2, v2);
        return (v1 == v2);
    }

    void dfs_on_single_tree(TreeNode* node,vector<int>& v)
    {
        if ( !node)
            return ;
        if ( !node->left && !node->right)
        {
            v.push_back(node->val);
            return ;
        }
        dfs_on_single_tree(node->left, v);
        dfs_on_single_tree(node->right, v);
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

