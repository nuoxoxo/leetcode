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
    int countNodes(TreeNode* root)
    {
        if (!root)
            return 0;
        deque<TreeNode *>   dq = {root};
        TreeNode    *node;
        int res = 0;
        int len, i;
        while (dq.size())
        {
            len = (int) dq.size();
            i = -1;
            while (++i < len)
            {
                node = dq.front();
                ++res;
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
