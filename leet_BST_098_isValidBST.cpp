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

class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        vector<int> arr;

        get_vals(root, arr);
        int i = 0;
        while (++i < (int) arr.size())
        {
            if (arr[i - 1] >= arr[i])    return false ;
        }
        return true ;
    }
    
    void    get_vals(TreeNode *node, vector<int>& arr)
    {
        if (!node)  return ;
        get_vals(node->left, arr);
        arr.push_back(node->val);
        get_vals(node->right, arr);
    }
};

