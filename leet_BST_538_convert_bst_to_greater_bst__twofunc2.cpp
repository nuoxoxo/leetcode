class Solution {
public:
    TreeNode* convertBST(TreeNode* root)
    {
        int total = 0;
        return reverse_inorder_traversal(root, total);
    }
    
    TreeNode*   reverse_inorder_traversal(TreeNode* node, int& total)
    {
        if (node)
        {
            reverse_inorder_traversal(node->right, total);
            total += node->val;
            node->val = total;
            reverse_inorder_traversal(node->left, total);
        }
        return node;
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


