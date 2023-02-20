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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if (!root)
            return {};

        vector<vector<int>> r;
        deque<TreeNode *>   D{root};
        int                 count = 0;

        while (!D.empty())
        {
            vector<int> temp;
            int         len = D.size();
            while (len--)
            {
                TreeNode    *node = D.front();
                
                temp.push_back(node->val);
                D.pop_front();
                if (node->left)
                    D.push_back(node->left);
                if (node->right)
                    D.push_back(node->right);
            }
            if (count % 2)
                reverse(temp.begin(), temp.end());
            ++count;
            r.push_back(temp);

        }
        return r;
    }
};








