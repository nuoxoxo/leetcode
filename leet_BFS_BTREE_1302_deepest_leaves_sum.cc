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
    int deepestLeavesSum(TreeNode* root)
    {
        deque<TreeNode *>   dq = {root};
        TreeNode    *node;
        int res, level;
        while (!dq.empty())
        {
            res = 0;
            level = (int) dq.size();
            while (level--)
            {
                // cout << level << endl;
                node = dq.front();
                res += node->val;
                dq.pop_front();
                if (node->left)
                    dq.push_back(node->left);
                if (node->right)
                    dq.push_back(node->right);
            }
        }
        return res;
    }
};




