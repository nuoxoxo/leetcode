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
        vector<TreeNode*>   nodes;
        int                 i = -1;

        inorder_push(root, nodes);
        while (++i < nodes.size() - 1)
        {
            nodes[i]->right = nodes[i + 1];
            nodes[i]->left = NULL;
        }
        nodes[i]->right = NULL;
        nodes[i]->left = NULL;
        return nodes[0] ;
    }
    
    void    inorder_push(TreeNode* node, vector<TreeNode*>& nodes)
    {
        if (node)
        {
            inorder_push(node->left, nodes);
            nodes.push_back(node);
            inorder_push(node->right, nodes);
        }
    }
};
