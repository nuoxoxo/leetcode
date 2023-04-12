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

        deque<TreeNode*>    ori;
        deque<TreeNode*>    clo;

        ori.push_back(o);
        clo.push_back(c);
        while (!ori.empty())
        {
            o = ori.front();
            ori.pop_front();
            c = clo.front();
            clo.pop_front();
            if (o == t)
                return c;
            if (o->left)
                ori.push_back(o->left);
            if (o->right)
                ori.push_back(o->right);
            if (c->left)
                clo.push_back(c->left);
            if (c->right)
                clo.push_back(c->right);
        }
        return NULL;
    }
};
