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
    TreeNode* pruneTree(TreeNode* node)
    {
        if (!node)
            return node;
        node->left = pruneTree(node->left);
        node->right = pruneTree(node->right);
        if (!node->left && !node->right && node->val == 0)
            return NULL;
        return node;
    }
};
