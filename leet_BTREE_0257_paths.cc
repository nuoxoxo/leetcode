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

    vector<string>  binaryTreePaths(TreeNode* root)
    {
        vector<string>      res;

        if (root)
            DFS(res, root, "");
        return (res);
    }

    void DFS(vector<string> & v, TreeNode *node, string s)
    {
        if ( !(node->left) && !(node->right))
            v.push_back(s + std::to_string(node->val));
        s += std::to_string(node->val) + "->";
        if (node->left)
            DFS(v, node->left, s);
        if (node->right)
            DFS(v, node->right, s);
    }
};
