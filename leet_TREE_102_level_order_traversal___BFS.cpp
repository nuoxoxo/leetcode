
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>>     vvi;
        deque<TreeNode *>       bfs;

        if (!root)
        {
            return {};
        }
        bfs.push_back(root);
        while (!bfs.empty())
        {
            vector<int> temp;
            TreeNode    *node;
            int         size;

            size = (int) bfs.size();
            while (size--)
            {
                node = bfs.front();
                bfs.pop_front();
                if (node->left)
                    bfs.push_back(node->left);
                if (node->right)
                    bfs.push_back(node->right);
                temp.push_back(node->val);
            }
            vvi.push_back(temp);
        }
        return (vvi);
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
