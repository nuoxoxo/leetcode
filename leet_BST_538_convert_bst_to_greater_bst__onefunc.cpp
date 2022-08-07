
class Solution {
public:

    int total = 0;

    TreeNode* convertBST(TreeNode* node)
    {
        if (node)
        {
            convertBST(node->right);
            total += node->val;
            node->val = total;
            convertBST(node->left);
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
