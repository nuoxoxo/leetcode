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
    TreeNode* trimBST(TreeNode* node, int low, int high)
    {
        if (!node)
            return node;
        if (node->val < low)
            return trimBST(node->right, low, high);
        if (node->val > high)
            return trimBST(node->left, low, high);
        node->right = trimBST(node->right, low, high);
        node->left = trimBST(node->left, low, high);
        return node ;
    }
};
