/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t)
    {
        if (!o)
            return NULL;
        if (o == t)
            return c;

        deque<TreeNode*>    dq;

        dq.push_back(c);
        while (!dq.empty())
        {
            c = dq.front();
            dq.pop_front();
            if (c->val == t->val)
                return c;
            if (c->left)
                dq.push_back(c->left);
            if (c->right)
                dq.push_back(c->right);
        }
        return NULL;
    }
};
