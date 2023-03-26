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
    bool isCompleteTree(TreeNode* root)
    {
        deque<TreeNode *>   E;
        bool                null_appears;

        null_appears = false;
        E.push_back(root);
        while (!E.empty())
        {
            TreeNode    *node;

            node = E.front();
            E.pop_front();
            if (!node)
            {
                null_appears = true;
            }
            else
            {
                if (null_appears)
                    return false;
                E.push_back(node->left);
                E.push_back(node->right);
            }
        }
        return true;
    }
};
