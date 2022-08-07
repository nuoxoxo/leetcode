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
    bool isSymmetric(TreeNode* node)
    {
        if (!node)
            return true;
        return isSame(node->left, node->right);
    }

    bool    isSame(TreeNode* L, TreeNode* R)
    {
        if (!L && !R)
            return true;
        if (!L || !R || L->val != R->val)
            return false;
        return isSame(L->left, R->right) && isSame(L->right, R->left);
    }
};
