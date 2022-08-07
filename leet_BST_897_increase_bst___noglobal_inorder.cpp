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

    TreeNode* increasingBST(TreeNode* root)
    {
        TreeNode*   dum = new TreeNode();
        TreeNode*   end = dum;

        inorder_traversal(root, end);
        return dum->right;
    }

    void inorder_traversal(TreeNode *node, TreeNode *&end)
    {
        if (node)
        {
            inorder_traversal(node->left, end);

            end->right = node;
            end = node;
            end->left = NULL;

            inorder_traversal(node->right, end);
        }
    }
};
