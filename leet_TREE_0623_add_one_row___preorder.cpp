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
    TreeNode* addOneRow(TreeNode* node, int val, int depth)
    {
        TreeNode    *temp1;
        TreeNode    *temp2;

        if (! node)
            return (NULL);
        if (depth == 1)
        {
            temp1 = new TreeNode(val);
            temp1->left = node;
            return (temp1);            
        }
        if (depth == 2)
        {
            temp1 = new TreeNode(val);
            temp2 = new TreeNode(val);
            temp1->left = node->left;
            temp2->right = node->right;
            node->left = temp1;
            node->right = temp2;
            return (node);
        }
        depth--;
        node->left = addOneRow(node->left, val, depth);
        node->right = addOneRow(node->right, val, depth);
        return (node);
    }
};
