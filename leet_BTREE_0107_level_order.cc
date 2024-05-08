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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {

        // BFS

        // assert (root); // will fail
        if ( !root)
            return {};
        vector<vector<int>> res;
        deque<TreeNode*> Q;
        Q.push_back(root);
        while (!Q.empty())
        {
            vector<int> todo;
            int N = Q.size();
            int i = -1;
            while (++i < N)
            {
                TreeNode * node = Q.front();
                Q.pop_front();
                todo.push_back(node->val);
                if (node->left)
                    Q.push_back(node->left);
                if (node->right)
                    Q.push_back(node->right);
            }
            res.push_back(todo);
        }
        reverse(begin(res), end(res));
        return res;
    }
};
