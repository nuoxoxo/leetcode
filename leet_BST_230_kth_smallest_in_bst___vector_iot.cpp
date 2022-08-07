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
    int kthSmallest(TreeNode* root, int k)
    {
        vector<int> nodes;
        iot(root, nodes);
        return nodes[k - 1];
    }

    void    iot(TreeNode* node, vector<int>& nodes)
    {
        if (node)
        {
            iot(node->left, nodes);
            nodes.push_back(node->val);
            iot(node->right, nodes);
        }
    }
};
