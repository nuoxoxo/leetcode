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
    int sumOfLeftLeaves(TreeNode* root)
    {
        vector<int (*) (TreeNode *)> Solutions {
            // BFS,
            // DFS,
            DFS_Alt,
        };
        return Solutions[ 0 ]( root );
    }

    static int BFS(TreeNode * node)
    {
        int res = 0;
        deque<pair<TreeNode *, bool>> Q {{node, false},};

        while (!Q.empty())
        {
            pair<TreeNode *, bool> temp = Q.front();
            TreeNode * curr = temp.first;
            bool LEFT = temp.second;
            Q.pop_front();
            if (LEFT && ! curr->left && ! curr->right)
            {
                res += curr->val;
            }
            if (curr->left)
            {
                Q.push_back( {curr->left, true} );
            }
            if (curr->right)
            {
                Q.push_back( {curr->right, false} );
            }
        }
        return res;
    }

    static int DFS(TreeNode * node)
    {
        //      Wrong writitng
        // int dfs = [](TreeNode * node, bool LEFT)

        //      Wrong writitng
        // auto dfs = [](TreeNode * node, bool LEFT) -> int
        //      the lambda func's definition is not complete, 
        //      while the lambda dfs is referring to itself within its body

        function<int(TreeNode *, bool)> dfs = [&](TreeNode * node, bool LEFT) -> int
        {
            if (!node)
            {
                return 0;
            }
            if ( ! node->left && ! node->right)
            {
                if ( ! LEFT)
                {
                    return 0;
                }
                return node->val;
            }
            return dfs(node->left, true) + dfs(node->right, false);
        };

        return dfs(node, false);
    }

    static int DFS_Alt(TreeNode * node)
    {
        if ( ! node)
        {
            return 0;
        }
        if (node->left && ! node->left->left && ! node->left->right)
        {
            return node->left->val + DFS_Alt(node->right);
        }
        return DFS_Alt(node->left) + DFS_Alt(node->right);
    }

};
