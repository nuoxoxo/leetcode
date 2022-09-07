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
    string tree2str(TreeNode* root)
    {
        vector<string>  res;
        string          r;

        preorder(root, res);
        for (string s: res)
            r += s;
        return r.substr(1, r.length() - 2);
    }

    void    preorder(TreeNode *node, vector<string>& res)
    {
        if (!node)
            return ;
        res.push_back("(");
        res.push_back(to_string(node->val));
        if (! node->left && node->right)
        {
            res.push_back("()");
        }
        preorder(node->left, res);
        preorder(node->right, res);
        res.push_back(")");
    }
};
