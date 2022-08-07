
class Solution {
public:
    TreeNode* invertTree(TreeNode* node) {
        if (!node)
            return NULL ;
        invertTree(node->right);
        invertTree(node->left);
        swap( node->left, node->right );
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
