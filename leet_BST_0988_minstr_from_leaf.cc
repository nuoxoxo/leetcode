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
        vector<string(*)(TreeNode *)> Solutions {
            DFS,
        };

        return Solutions[0](root);
    }

    static string DFS(TreeNode * root)
    {
        string res;
        string curr;

        std::function<void(TreeNode *, string, string &)> recurse = [&](TreeNode * node, string curr, string & res)
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
            recurse (node->left, curr, res);
            recurse (node->right, curr, res);
        };
        recurse (root, curr, res);
        return res;
    }
};
