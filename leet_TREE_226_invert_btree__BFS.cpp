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
    TreeNode* invertTree(TreeNode* root)
    {
        if (!root)
            return root ;

        deque<TreeNode*>    q;

        q.push_back(root);
        while (!q.empty())
        {
            TreeNode*   node = q.front();

            q.pop_front();
            swap(node->left, node->right);
            if (node->left)
                q.push_back(node->left);
            if (node->right)
                q.push_back(node->right);
        }
        return root ;
    }
};
