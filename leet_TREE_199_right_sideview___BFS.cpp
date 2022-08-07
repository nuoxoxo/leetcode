class Solution {
public:
    vector<int> rightSideView(TreeNode* node)
    {
        deque<TreeNode*>    dq;
        vector<int>         res;
        TreeNode            *ptr;
        int                 len;
        int                 i;

        if (!node)
            return {};
        dq.push_back(node);
        while (!dq.empty())
        {
            len = (int) dq.size();
            i = 0;
            while (++i < len + 1)
            {
                ptr = dq.front();
                dq.pop_front();
                if (i == len)
                    res.push_back(ptr->val);
                if (ptr->left)
                    dq.push_back(ptr->left);
                if (ptr->right)
                    dq.push_back(ptr->right);
            }
        }
        return res;
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

