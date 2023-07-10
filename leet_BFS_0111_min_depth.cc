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
    int minDepth(TreeNode* root)
    {
        if (!root)
            return (0);

        deque<TreeNode*>    dq = { root } ;
        int                 depth = 1 ;

        while (!dq.empty())
        {
            int i = -1, len = dq.size() ;

            while (++i < len)
            {
                TreeNode*   temp = dq.front() ;

                dq.pop_front() ;
                if (!temp->left && !temp->right)
                    return depth ;
                if (temp->left)
                    dq.push_back(temp->left);
                if (temp->right)
                    dq.push_back(temp->right);
            }
            ++ depth ;
        }
        return depth ;
    }
};
