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
    int minDiffInBST(TreeNode* root)
    {
        vector<int> v;
        inorder(root, v);
        sort(v.begin(), v.end());
        int i = -1, res = 2147483647;
        while (++i < v.size() - 1)
        {
            int diff = v[i + 1] - v[i];
            res = res > diff ?diff :res;
        }
        return res;
    }

    void    inorder(TreeNode* node, vector<int> & v)
    {
        if (!node)
            return ;
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
};
