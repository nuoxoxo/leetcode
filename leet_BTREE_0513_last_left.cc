class Solution {
public:
    int findBottomLeftValue(TreeNode* node)
    {
        deque<TreeNode*>    dq;
        TreeNode*           n;  /// last node

        dq.push_back(node);
        while (!dq.empty())
        {
            TreeNode*   p = dq.front();

            n = p;
            dq.pop_front();

            if (p->right)
                dq.push_back(p->right);
            /// check the right node first to 
            /// make sure the last node is a Left node

            if (p->left)
                dq.push_back(p->left);
        }
        return n->val;
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
