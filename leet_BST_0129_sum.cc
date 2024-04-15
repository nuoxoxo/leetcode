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
    int sumNumbers(TreeNode* root)
    {
        return (DFS(root, 0));
    }

    int DFS(TreeNode *node, int curr)
    {
        if (!node)
        {
            return 0;
        }
        curr = 10 * curr + node->val;
        if (!node->left && !node->right)
        {
            return curr;
        }
        return DFS(node->left, curr) + DFS(node->right, curr);

    }
};
