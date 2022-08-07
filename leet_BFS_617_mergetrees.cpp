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
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2)
    {
        if (!r1 && !r2)
            return (NULL);
        if (!r1)
            return (r2) ;
        if (!r2)
            return (r1) ;
        deque<TreeNode*>    dq1;
        deque<TreeNode*>    dq2;
        dq1.push_back(r1);
        dq2.push_back(r2);
        while (!dq2.empty())
        {
            TreeNode*   p1 = dq1.front();
            TreeNode*   p2 = dq2.front();

            p1->val += p2->val;
            dq1.pop_front();
            dq2.pop_front();
            if (p2->left)
            {
                if (p1->left)
                {
                    dq1.push_back(p1->left);
                    dq2.push_back(p2->left);
                }
                else
                    p1->left = p2->left ;
            }
            if (p2->right)
            {
                if (p1->right)
                {
                    dq1.push_back(p1->right);
                    dq2.push_back(p2->right);
                }
                else
                    p1->right = p2->right ;
            }
        }
        return (r1) ;
    }
};
