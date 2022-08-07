class Solution {
public:
    TreeNode* invertTree(TreeNode* node) {
        if (!node)  return node ;
        swap( node->left, node->right );
        invertTree(node->right);
        invertTree(node->left);
        return node ;
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
