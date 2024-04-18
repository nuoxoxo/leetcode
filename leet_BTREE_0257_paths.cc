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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res;
        DFS(res, root, "");
        return res;
    }

    void DFS(vector<string> & vs, TreeNode * node, string s)
    {
        if ( !(node->left) && !(node->right))
            vs.push_back ( s + to_string(node->val));
        s += to_string(node->val) + "->";
        if (node->left)
            DFS(vs, node->left, s);
        if (node->right)
            DFS(vs, node->right, s);
    }
};
