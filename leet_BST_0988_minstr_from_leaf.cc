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
    string smallestFromLeaf(TreeNode* root)
    {
        string res, curr;
        DFS(root, curr, res);

        return res;
    }

    void DFS(TreeNode * node, string curr, string & res)
    {
        if ( ! node)
            return ;
        string EMPTY = "";
        curr = EMPTY + (char)(node->val + 'a') + curr;
        if ( ! node->left && ! node->right)
        {
            if (res == "" || res > curr)
            {
                res = curr;
            }
            return ;
        }
        DFS(node->left, curr, res);
        DFS(node->right, curr, res);
    }
};
